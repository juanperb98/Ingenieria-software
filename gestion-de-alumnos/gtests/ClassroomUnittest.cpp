/* gtests/ClassroomUnittest.hpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * Unittests for Classroom class
 *
 * Not doing mocks becouse of the low complexity of the program
 */
 

#include "gtest/gtest.h"
#include "Classroom.hpp"

TEST(Classroom, Builder){
	Classroom classroom;
	EXPECT_EQ(classroom.getStudents().size(), 0);
}


TEST(Classroom, adder){
	Classroom classroom;
	time_t date = time(nullptr);

	Student s1;	
	s1.setId("123");
	s1.setName("pepe");
	s1.setLastName("perez");
	s1.setPhone(689111111);
	s1.setEmail("pepe@uco.es");
	s1.setAddress("calle de pepe");
	s1.setHighestCourse(3);
	s1.setGroupNumber(4);
	s1.setBirthAt(date);
	s1.setIsLeader(true);
	
	EXPECT_EQ(classroom.addStudent(s1), SUCCESS);
	EXPECT_EQ(classroom.getStudents().size(), 1);
}

TEST(Classroom, adderDuplicated){
	Classroom classroom;
	time_t date = time(nullptr);

	Student s1;
	s1.setId("123");
	s1.setName("pepe");
	s1.setLastName("perez");
	s1.setPhone(689111111);
	s1.setEmail("pepe@uco.es");
	s1.setAddress("calle de pepe");
	s1.setHighestCourse(3);
	s1.setGroupNumber(4);
	s1.setBirthAt(date);
	s1.setIsLeader(true);

	EXPECT_EQ(classroom.addStudent(s1), SUCCESS);
	EXPECT_EQ(classroom.addStudent(s1), CLASSROOM_DUPLICATED_STUDENT);
	EXPECT_EQ(classroom.getStudents().size(), 1);
}

TEST(Classroom, addedMultipleStudents){
	Classroom classroom;
	time_t date = time(nullptr);

	Student s1;
	s1.setId("123");
	s1.setName("pepe");
	s1.setLastName("perez");
	s1.setPhone(689111111);
	s1.setEmail("pepe@uco.es");
	s1.setAddress("calle de pepe");
	s1.setHighestCourse(3);
	s1.setGroupNumber(4);
	s1.setBirthAt(date);
	s1.setIsLeader(true);
	
	Student s2;
	s2.setId("1234");
	s2.setName("juan");
	s2.setLastName("lopez");
	s2.setPhone(689112111);
	s2.setEmail("juan@uco.es");
	s2.setAddress("calle de juan");
	s2.setHighestCourse(2);
	s2.setGroupNumber(3);
	s2.setBirthAt(date);
	s2.setIsLeader(false);
	
	EXPECT_EQ(classroom.addStudent(s1), SUCCESS);
	EXPECT_EQ(classroom.addStudent(s2), SUCCESS);
	EXPECT_EQ(classroom.getStudents().size(), 2);
	EXPECT_EQ(classroom.getStudents()[0].getId(), s1.getId());
	EXPECT_EQ(classroom.getStudents()[1].getId(), s2.getId());
	
}


TEST(Classroom, deleteStudent){
	Classroom classroom;
	time_t date = time(nullptr);

	Student s1;
	s1.setId("123");
	s1.setName("pepe");
	s1.setLastName("perez");
	s1.setPhone(689111111);
	s1.setEmail("pepe@uco.es");
	s1.setAddress("calle de pepe");
	s1.setHighestCourse(3);
	s1.setGroupNumber(4);
	s1.setBirthAt(date);
	s1.setIsLeader(true);
	
	Student s2;
	s2.setId("1234");
	s2.setName("juan");
	s2.setLastName("lopez");
	s2.setPhone(689112111);
	s2.setEmail("juan@uco.es");
	s2.setAddress("calle de juan");
	s2.setHighestCourse(2);
	s2.setGroupNumber(3);
	s2.setBirthAt(date);
	s2.setIsLeader(false);
	
	classroom.addStudent(s1);
	classroom.addStudent(s2);
	
	EXPECT_EQ(classroom.getStudents().size(), 2);
	EXPECT_EQ(classroom.deleteStudent(s1), SUCCESS);
	// EXPECT_EQ(classroom.getStudents().size(), 1);
	// EXPECT_EQ(classroom.deleteStudent(s1), CLASSROOM_STUDENT_NOT_FOUND);
	// EXPECT_EQ(classroom.deleteStudent(s2), SUCCESS);
	// EXPECT_EQ(classroom.getStudents().size(), 0);
	// EXPECT_EQ(classroom.deleteStudent(s2), CLASSROOM_STUDENT_NOT_FOUND);
	
}