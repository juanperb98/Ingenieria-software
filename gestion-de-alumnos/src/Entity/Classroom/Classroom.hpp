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
#include "errorCodes.hpp"
#include "Student.hpp"

#include <regex>
#include <ctime>
#include <string>

class Classroom{
	private:

		std::vector<Student> students_;


	public:
		int addStudent(Student student);
		int deleteStudent(Student student);
		std::vector<Student> getStudents();
		int searchStudent( Student & student,std::vector<Student> &students);
};

#endif
