/* src/Controller/DBController.cpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * Source code of the sysmtem's DBController
 */


#include "DBController.hpp"

DBController::DBController(std::string path): _filePath(path){}

std::string DBController::getPath(){
	return _filePath;
}

int DBController::save(Classroom classroom){
	
	// checks if file exist
	std::ifstream testFile;
	if ( testFile.is_open() )
		return DBCONTROLLER_FILE_EXISTS;
	
	// if the file exists, close it and open it in wirte binary mode
	testFile.close();	
	std::ofstream file;


	file.open(this->getPath());

	
	// checks if it's open
	if ( !file.is_open() )
		return DBCONTROLLER_FILE_NOT_FOUND;
	
	// writes the students to file
	std::vector<Student> students;

	Student s;
	students = classroom.getStudents();
	for (size_t i = 0; i < students.size(); i++) {
		s = students[i];
		
		file<<s.getId()<<';'<<s.getName()<<';'<<s.getLastName()<<';'<<s.getPhone()<<';'<<s.getEmail()<<';'<<s.getAddress()<<';'<<s.getHighestCourse()<<';'<<s.getGroupNumber()<<';'<<(int)s.getBirthAtUnix()<<';'<<s.getIsLeader()<<'\n';
		

	}
	
	file.close();	
	return SUCCESS;
}


int DBController::load(Classroom& classroom){
	// checks if file exist
	std::ifstream file;
	file.open(this->getPath().c_str());

	if ( !file.is_open() )
		return DBCONTROLLER_FILE_NOT_FOUND;
	
	// loads the file into Classroom
	Student student;

	std::string line;
	std::string field;
	Student s;
	while ( getline (file,line) ){
		
		// id
		field = line.substr(0, line.find(";"));
		line = line.substr(line.find(";")+1, line.size());
		student.setId(field);
		
		// name
		field = line.substr(0, line.find(";"));
		line = line.substr(line.find(";")+1, line.size());
		student.setName(field);
		
		// last name
		field = line.substr(0, line.find(";"));
		line = line.substr(line.find(";")+1, line.size());
		student.setLastName(field);
		
		// phone
		field = line.substr(0, line.find(";"));
		line = line.substr(line.find(";")+1, line.size());
		student.setPhone((unsigned int) atoi(field.c_str()));
		
		// email
		field = line.substr(0, line.find(";"));
		line = line.substr(line.find(";")+1, line.size());
		student.setEmail(field);
		
		// eddress
		field = line.substr(0, line.find(";"));
		line = line.substr(line.find(";")+1, line.size());
		student.setAddress(field);
		
		// HighestCourse
		field = line.substr(0, line.find(";"));
		line = line.substr(line.find(";")+1, line.size());
		student.setHighestCourse((unsigned short int) atoi(field.c_str()));
		
		// GroupNumber
		field = line.substr(0, line.find(";"));
		line = line.substr(line.find(";")+1, line.size());
		student.setGroupNumber((unsigned int) atoi(field.c_str()));
		
		// birthAt
		field = line.substr(0, line.find(";"));
		line = line.substr(line.find(";")+1, line.size());
		student.setBirthAt((time_t) atoi(field.c_str()));
		
		// phone
		field = line.substr(0, line.find(";"));
		line = line.substr(line.find(";")+1, line.size());
		student.setIsLeader((bool) atoi(field.c_str()));
		
		
		classroom.addStudent(student);
		
	}
	file.close();

	return SUCCESS;
}

/* Removes the file if it exists 
 * if the path is not set, it does nothing
 *
 * Be carefull of what path do you use!
 */
int DBController::clear(){
	if ( getPath() == "" )
		return DBCONTROLLER_INVALID_PATH;
	if ( remove(getPath().c_str()) != 0 )
		return DBCONTROLLER_FILE_NOT_FOUND;

	return SUCCESS;
}
