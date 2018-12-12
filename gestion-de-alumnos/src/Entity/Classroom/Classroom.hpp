/* src/Entity/Classroom/Classroom.hpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *	Hector Romero Lopez
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

#define MAX_STUDENTS 150

class Classroom{
	private:

		std::vector<Student> students_;


	public:
		int addStudent(Student const & student);
		int __addStudent(Student const & student);
		int deleteStudent(Student const & student);
		std::vector<Student> getStudents()const;
		int searchStudent(Student const & student,
				  std::vector<Student> &students)const;
		
		/* Warning! the leader value is always set!!!
		 * If you want to not modify it use the function
		 * simpleModifyStudent function
		 */
	 	int modifyStudent(Student const & target, Student const & newData);
		
		/* This funciton does not overwrite the is selected
		 * variable, if you want to modify it use the 
		 * modifyStudent function
		 */
		int simpleModifyStudent(Student const & target, Student const & newData);
};

#endif
