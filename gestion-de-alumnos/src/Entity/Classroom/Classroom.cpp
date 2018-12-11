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


int Classroom::searchStudent(Student & student,
			     std::vector<Student> &students){
	//Searching for students with progressive filters and some basic regex
	if ( students_.empty() )
		return CLASSROOM_EMPTY;
	
	if ( student.getId() ==  ""
	&& student.getName() == ""
	&& student.getLastName() == "" )
		return CLASSROOM_STUDENT_NOT_FOUND;
	
	if ( (student.getId() !=  ""  )){
		students.clear();
		std::vector<Student>::iterator studentIterator;
		for (studentIterator = students_.begin();studentIterator != students_.end();studentIterator++){
			std::string studentId = studentIterator->getId();
			std::string customRegex = ".*("+student.getId()+").*";
			std::regex re(customRegex);
			std::smatch match;
			if (std::regex_search(studentId,match,re))
				students.push_back(*studentIterator);
		}
		if (student.getName() != "" ){
			std::vector<Student> studentsAux;
			std::vector<Student>::iterator studentIterator;
			for (studentIterator=students.begin();studentIterator!=students.end();studentIterator++){
				std::string studentName = studentIterator->getName();
				std::string customRegex = ".*("+student.getName()+").*";
				std::regex re(customRegex);
				std::smatch match;
				if (std::regex_search(studentName,match,re))
					studentsAux.push_back(*studentIterator);
			}
			students = studentsAux;
		}
		if(student.getLastName() != ""){
		std::vector<Student>::iterator studentIterator;
		std::vector<Student> studentsAux;
			for (studentIterator = students.begin();studentIterator!=students.end();studentIterator++){
				std::string regexPattern = studentIterator->getLastName();
				std::string customRegex = ".*("+student.getLastName()+").*";
				std::regex re(customRegex);
				std::smatch match;
				if (std::regex_search(regexPattern,match,re)){
					studentsAux.push_back(*studentIterator);
				}
			}
			students = studentsAux;
		}
	}
	return SUCCESS;
}

