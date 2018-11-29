/* gtests/StudentUnittest.hpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * Unittests for Student class
 *
 * Not doing mocks becouse of the low complexity of the program
 */
 

#include "gtest/gtest.h"
#include "Student.hpp"

TEST(Student, Builder){
	Student student;

	EXPECT_EQ(student.getId(),"");
	EXPECT_EQ(student.getName(),"");
	EXPECT_EQ(student.getLastName(),"");
	EXPECT_EQ(student.getPhone(),0);
	EXPECT_EQ(student.getEmail(),"");
	
	tm st = student.getBirthAt();	
	EXPECT_EQ(st.tm_sec, 0);
	EXPECT_EQ(st.tm_min, 0);
	EXPECT_EQ(st.tm_hour, 1);
	EXPECT_EQ(st.tm_mday, 1);
	EXPECT_EQ(st.tm_mon, 0);
	EXPECT_EQ(st.tm_year, 70);
	EXPECT_EQ(st.tm_wday, 4);
	EXPECT_EQ(st.tm_yday, 0);
	EXPECT_EQ(st.tm_isdst, 0);
	
	EXPECT_EQ(student.getBirthAtUnix(),0);
	EXPECT_EQ(student.getAddress(),"");
	EXPECT_EQ(student.getIsLeader(),false);
	EXPECT_EQ(student.getGroupNumber(),0);
	EXPECT_EQ(student.getHighestCourse(),0);
}


TEST(Student, Seters){
	time_t date = time(nullptr);
	Student student;
	
	EXPECT_EQ(SUCCESS,student.setId("123"));
	EXPECT_EQ(SUCCESS,student.setName("pepe"));
	EXPECT_EQ(SUCCESS,student.setLastName("perez"));
	EXPECT_EQ(SUCCESS,student.setPhone(689111111));
	EXPECT_EQ(SUCCESS,student.setEmail("pepe@uco.es"));
	EXPECT_EQ(SUCCESS,student.setAddress("calle de pepe"));
	EXPECT_EQ(SUCCESS,student.setHighestCourse(3));
	EXPECT_EQ(SUCCESS,student.setGroupNumber(4));
	EXPECT_EQ(SUCCESS,student.setBirthAt(date));
	EXPECT_EQ(SUCCESS,student.setIsLeader(true));
	
	EXPECT_EQ(student.getId(),"123");
	EXPECT_EQ(student.getName(),"pepe");
	EXPECT_EQ(student.getLastName(),"perez");
	EXPECT_EQ(student.getPhone(),689111111);
	EXPECT_EQ(student.getEmail(),"pepe@uco.es");	
	EXPECT_EQ(student.getBirthAtUnix(),date);
	EXPECT_EQ(student.getAddress(),"calle de pepe");
	EXPECT_EQ(student.getIsLeader(),true);
	EXPECT_EQ(student.getGroupNumber(),4);
	EXPECT_EQ(student.getHighestCourse(),3);
}

TEST(Student, Faulty_Seters){
	Student student;
	
	EXPECT_EQ(STUDENT_INVALID_PHONE,student.setPhone(68911111));
	EXPECT_EQ(STUDENT_INVALID_PHONE,student.setPhone(1));
	EXPECT_EQ(STUDENT_INVALID_PHONE,student.setPhone(-1));
	EXPECT_EQ(STUDENT_INVALID_PHONE,student.setPhone(99999999));
	EXPECT_EQ(STUDENT_INVALID_EMAIL,student.setEmail("pepe@.es"));
	EXPECT_EQ(STUDENT_INVALID_EMAIL,student.setEmail("pepe@uco."));
	EXPECT_EQ(STUDENT_INVALID_EMAIL,student.setEmail("pepe@."));
	EXPECT_EQ(STUDENT_INVALID_EMAIL,student.setEmail("pepe"));
	EXPECT_EQ(STUDENT_INVALID_EMAIL,student.setEmail("pepe@"));
	EXPECT_EQ(STUDENT_INVALID_EMAIL,student.setEmail("@uco.es"));
	EXPECT_EQ(STUDENT_INVALID_EMAIL,student.setEmail("uco.es"));
	EXPECT_EQ(STUDENT_INVALID_DATE,student.setBirthAt(-1));
	
	EXPECT_EQ(student.getPhone(),0);
	// EXPECT_EQ(student.getEmail(),"");
	EXPECT_EQ(student.getBirthAtUnix(),0);
}
