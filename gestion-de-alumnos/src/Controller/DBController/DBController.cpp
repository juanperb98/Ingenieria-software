/* src/Controller/DBController.cpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * Source code of the sysmtem's DBController
 */


#include "DBController.hpp"

DBController::DBController(std::string path): _filePath(path){};

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
	file.open(this->getPath(), std::ofstream::binary);
	
	// checks if it's open
	if ( !file.is_open() )
		return DBCONTROLLER_FILE_NOT_FOUND;
	
	// writes the students to file
	std::vector<Student> students;
	students = classroom.getStudents();
	for (size_t i = 0; i < students.size(); i++) {
		// TODO: it just needs to work...
		// file.write(students[i], sizeof(Student));
	}
	
	file.close();	
	return SUCCESS;
}

int DBController::load(Classroom* classroom){
	// checks if file exist
	std::ifstream file;
	if ( !file.is_open() )
		return DBCONTROLLER_FILE_NOT_FOUND;
	
	// loads the file into Classroom
	Student student;
	/*
	while ( !EOF ){
		// TODO: get it to work...
		file.read(student, sizeof(student));
		classroom->addStudent(student);
	}
	*/
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
