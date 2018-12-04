/* src/Entity/Classroom/Classroom.cpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * Sorce code for Classroom class
 */


#include "Classroom.hpp"

std::list<Student> Classrom::getStudents(){
	return students;
}