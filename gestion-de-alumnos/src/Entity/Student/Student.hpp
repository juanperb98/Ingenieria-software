/* src/Entity/Student/Student.hpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
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
		int setId(std::string id);
		std::string getId();
		
		int setName(std::string name);
		std::string getName();
		
		int setLastName(std::string lastName);
		std::string getLastName();
		
		int setPhone(int phone);
		int getPhone();	
		
		int setEmail(std::string email);
		std::string getEmail();	
		
		int setAddress(std::string address);
		std::string getAddress();
		
		int setHighestCourse(unsigned short int highestCourse);
		unsigned short int getHighestCourse();
		
		int setGroupNumber(unsigned int groupNumber);
		unsigned int getGroupNumber();
		
		int setBirthAt(tm birthAt);
		// overloaded function for unix time
		int setBirthAt(time_t birthAt);
		tm getBirthAt();
		// returns in unix's time
		time_t getBirthAtUnix();
		
		int setIsLeader(bool isLeader);
		bool getIsLeader();
};

#endif
