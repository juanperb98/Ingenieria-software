/* gtests/DBControllerUnittest.hpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * Unittests for DBController class
 *
 * Not doing mocks becouse of the low complexity of the program
 */


#include "gtest/gtest.h"
#include "DBController.hpp"
#include "Classroom.hpp"

TEST(DBController, Builder){
	std::string path = "/tmp/dbtest.bin";
	DBController db(path);
	EXPECT_EQ(db.getPath(), path);
}

TEST(DBController, loader_empty_and_rm){
	Classroom* c1;
	std::string path = "/tmp/dbtest.bin";
	DBController db(path);
	db.clear();
	EXPECT_EQ(db.clear(), DBCONTROLLER_FILE_NOT_FOUND);
	EXPECT_EQ(db.load(c1), DBCONTROLLER_FILE_NOT_FOUND);
}

TEST(DBController, setter_and_loader){
	Classroom classroom;
	Classroom classroom2;
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
	
	classroom.addStudent(s1);
	
	std::string path = "/tmp/dbtest.bin";
	DBController db(path);
	db.clear();
	EXPECT_EQ(db.save(classroom), SUCCESS);
	EXPECT_EQ(db.load(&classroom2), SUCCESS);
	// EXPECT_EQ(classroom2.getStudents()[0].getId(), s1.getId());
}	