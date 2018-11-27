/* gtests/StudentUnittest.hpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * Unittests for Student class
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
	
	student.setId("123");
	student.setName("pepe");
	student.setLastName("perez");
	student.setPhone(689111111);
	student.setEmail("pepe@uco.es");
	student.setAddress("calle de pepe");
	student.setHighestCourse(3);
	student.setGroupNumber(4);
	student.setBirthAt(date);
	student.setIsLeader(true);
	
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
