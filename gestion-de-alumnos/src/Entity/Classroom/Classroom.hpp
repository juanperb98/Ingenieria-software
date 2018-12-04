/* src/Entity/Classroom/Classroom.hpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * Headers of Classroom class
 */


#ifndef __CLASSROOM__
#define __CLASSROOM__

#include "compiler.hpp"
#include "ClassroomErrorCodes.hpp"
#include "ErrorCodes.hpp"
#include "Student.hpp"

#include <regex>
#include <ctime>
#include <string>
#include <list>

class Classrom{
	private:
		std::list<Student> students;

	public:
		int addStudent(Student student);
		int deleteStudent(Student student);
		std::list<Student> getStudents();
};

#endif
