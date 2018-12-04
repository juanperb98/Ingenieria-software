/* src/Entity/Classroom/Classroom.cpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * Sorce code for Classroom class
 */


#include "Classroom.hpp"

std::vector<Student> Classrom::getStudents(){
	return students;
}

int Classrom::addStudent(Student student){
	for (size_t i = 0; i < getStudents().size(); i++) {
		if ( unlikely(student.getId()==students[i].getId()) )
			return CLASSROOM_DUPLICATED_STUDENT;
	}
	students.push_back(student);
	return SUCCESS;
}