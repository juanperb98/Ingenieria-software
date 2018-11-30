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

TEST(DBController, Builder){
	std::string path = "/tmp/dbtest.bin";
	DBController db(path);
	EXPECT_EQ(db.getPath(), path);
}

TEST(DBController, loader_empty_and_rm){
	std::string path = "/tmp/dbtest.bin";
	DBController db(path);
	db.rmDB();
	EXPECT_EQ(db.getDB(), NULL);
}

TEST(DBController, _setter_and_loader){
	std::list<Student> students;
	std::string path = "/tmp/dbtest.bin";
	DBController db(path);
	EXPECT_EQ(db.setDB(students), SUCCESS);
	EXPECT_EQ(db.getDB(), students);
}	