/* src/Entity/Classroom/Classroom.cpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *	Hector Romero Lopez
 *
 * Sorce code for Classroom class
 */

#include "Classroom.hpp"

std::vector<Student> Classroom::getStudents(){
	return students_;

}

int Classroom::addStudent(Student student){
	for (size_t i = 0; i < getStudents().size(); i++) {
		if ( unlikely(student.getId()==students_[i].getId()) )
			return CLASSROOM_DUPLICATED_STUDENT;
	}
	students_.push_back(student);

	return SUCCESS;
}

int Classroom::deleteStudent(Student student){
	std::vector<Student>::iterator it;

	for (it = this->students_.begin(); it != this->students_.end(); it++) {
		if ( unlikely(student.getId() == it->getId()) ){
			this->students_.erase(it);
			return SUCCESS;
		}
	}
	return CLASSROOM_STUDENT_NOT_FOUND;
}


// int Classroom::searchStudent(Student & student,
// 			     std::vector<Student> &students){
// 	//Searching for students with progressive filters and some basic regex
// 	if ( students_.empty() )
// 		return CLASSROOM_EMPTY;
// 
// 	if ( student.getId() ==  ""
// 	&& student.getName() == ""
// 	&& student.getLastName() == "" )
// 		return CLASSROOM_STUDENT_NOT_FOUND;
// 
// 	students.clear();
// 	if ( (student.getId() !=  ""  )){
// 
// 		std::vector<Student>::iterator studentIterator;
// 		for (studentIterator = students_.begin();studentIterator != students_.end();studentIterator++){
// 			std::string studentId = studentIterator->getId();
// 			std::string customRegex = ".*("+student.getId()+").*";
// 			std::regex re(customRegex);
// 			std::smatch match;
// 			if (std::regex_search(studentId,match,re))
// 				students.push_back(*studentIterator);
// 		}
// 	}
// 	if (student.getName() != "" ){
// 		std::vector<Student> studentsAux;
// 		std::vector<Student>::iterator studentIterator;
// 		for (studentIterator=students.begin();studentIterator!=students.end();studentIterator++){
// 			std::string studentName = studentIterator->getName();
// 			std::string customRegex = ".*("+student.getName()+").*";
// 			std::regex re(customRegex);
// 			std::smatch match;
// 			if (std::regex_search(studentName,match,re))
// 				studentsAux.push_back(*studentIterator);
// 		}
// 		students = studentsAux;
// 	}
// 	if(student.getLastName() != ""){
// 	std::vector<Student>::iterator studentIterator;
// 	std::vector<Student> studentsAux;
// 		for (studentIterator = students.begin();studentIterator!=students.end();studentIterator++){
// 			std::string regexPattern = studentIterator->getLastName();
// 			std::string customRegex = ".*("+student.getLastName()+").*";
// 			std::regex re(customRegex);
// 			std::smatch match;
// 			if (std::regex_search(regexPattern,match,re)){
// 				studentsAux.push_back(*studentIterator);
// 			}
// 		}
// 		students = studentsAux;
// 	}
// 
// 	return SUCCESS;
// }


int Classroom::searchStudent(Student & student,
			     std::vector<Student> &students){
	// loads all the students in the vector
	students = this->getStudents();
	
	//filters out the non matching students
	std::vector<Student>::iterator studentIterator;
	std::string regexPattern;
	
	if ( students.size() == 0 )
		return CLASSROOM_EMPTY;
	
	for ( studentIterator = students.begin(); studentIterator != students.end(); studentIterator++ ){
		
		//set up the regexs
		regexPattern = ".*("+student.getId()+").*";
		std::regex idRegex(regexPattern);
		regexPattern = ".*("+student.getName()+").*";
		std::regex nameRegex(regexPattern);
		regexPattern = ".*("+student.getLastName()+").*";
		std::regex lastNameRegex(regexPattern);
		
		
		// if field is defined and not match, erase it
		if ( student.getId() != "" 
		&& ( !std::regex_match(studentIterator->getId(), idRegex)) )
			students.erase(studentIterator);
		
		if ( student.getName() != "" 
		&& ( !std::regex_match(studentIterator->getName(), nameRegex)) )
			students.erase(studentIterator);
			
		if ( student.getLastName() != "" 
		&& ( !std::regex_match(studentIterator->getLastName(), lastNameRegex)) )
			students.erase(studentIterator);
	}
	
	return SUCCESS;
}


int Classroom::modifyStudent(Student target, Student newData){
	std::vector<Student> students;
	this->searchStudent(target, students);
	
	// checks for search errors, only one student must be found
	if ( students.size() == 0 )
		return CLASSROOM_STUDENT_NOT_FOUND;
	if ( students.size() > 1 )
		return CLASSROOM_MULTIPLES_OCURRENCES;
	
	Student student = students[0];
	
	this->deleteStudent(students[0]);
	
	if ( newData.getId() != "" )
		student.setId(newData.getId());
	
	if ( newData.getName() != "" )
		student.setName(newData.getName());
	
	if ( newData.getLastName() != "" )
		student.setLastName(newData.getLastName());
	
	if ( newData.getPhone() != 0 )
		student.setPhone(newData.getPhone());
	
	if ( newData.getEmail() != "" )
		student.setEmail(newData.getEmail());
	
	
	this->addStudent(student);
	
	return SUCCESS;
}

