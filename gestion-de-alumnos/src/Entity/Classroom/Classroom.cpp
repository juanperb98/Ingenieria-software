/* src/Entity/Classroom/Classroom.cpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * Sorce code for Classroom class
 */


#include "Classroom.hpp"

std::vector<Student> Classroom::getStudents(){
	return students;
}

int Classroom::addStudent(Student student){
	for (size_t i = 0; i < getStudents().size(); i++) {
		if ( unlikely(student.getId()==students[i].getId()) )
			return CLASSROOM_DUPLICATED_STUDENT;
	}
	students.push_back(student);
	return SUCCESS;
}

int Classroom::deleteStudent(Student student){
	std::vector<Student>::iterator it;
	for (it = this->students.begin(); it != this->students.end(); it++) {
		if ( unlikely(student.getId() == it->getId()) ){
			this->students.erase(it);
			return SUCCESS;
		}
	}
	return CLASSROOM_STUDENT_NOT_FOUND;
}