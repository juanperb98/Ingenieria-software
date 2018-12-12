/* src/Entity/Student/Student.hpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *	Hector Romero Lopez
 *
 * Headers of Student class
 */


#ifndef __STUDENT__
#define __STUDENT__

#include "compiler.hpp"
#include "StudentErrorCodes.hpp"
#include "errorCodes.hpp"

#include <regex>
#include <ctime>
#include <string>

#include <iostream>

class Student{
	private:
		std::string _id = "";
		std::string _name = "";
		std::string _lastName = "";
		unsigned int _phone = 0;
		std::string _email = "";
		std::string _address = "";
		unsigned short int _highestCourse = 0;
		unsigned int _groupNumber = 0;
		time_t _birthAt = 0;
		bool _isLeader = false;

	public:
		Student(std::string id);
		Student();
		Student(Student const & student);
		
		
		int setId(std::string id);
		std::string getId()const;

		int setName(std::string name);
		std::string getName()const;

		int setLastName(std::string lastName);
		std::string getLastName()const;

		int setPhone(int phone);
		int getPhone()const;

		int setEmail(std::string email);
		std::string getEmail()const;

		int setAddress(std::string address);
		std::string getAddress()const;

		int setHighestCourse(unsigned short int highestCourse);
		unsigned short int getHighestCourse()const;

		int setGroupNumber(unsigned int groupNumber);
		unsigned int getGroupNumber()const;

		int setBirthAt(tm birthAt);
		// overloaded function for unix time
		int setBirthAt(time_t birthAt);
		tm getBirthAt()const;
		// returns in unix's time
		time_t getBirthAtUnix()const;

		int setIsLeader(bool isLeader);
		bool getIsLeader()const;
};

#endif
