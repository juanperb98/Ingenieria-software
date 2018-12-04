/* gtests/ClassromUnittest.hpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * Unittests for Classrom class
 *
 * Not doing mocks becouse of the low complexity of the program
 */
 

#include "gtest/gtest.h"
#include "Classroom.hpp"

TEST(Classrom, Builder){
	Classrom classrom;
	EXPECT_EQ(classrom.getStudents().size(), 0);
}

