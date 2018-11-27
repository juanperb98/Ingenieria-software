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
		Student& setId(std::string id);
		std::string getId();		
		
		Student& setName(std::string name);
		std::string getName();
		
		Student& setLastName(std::string lastName);
		std::string getLastName();		
		
		Student& setPhone(int phone);
		int getPhone();		
		
		Student& setEmail(std::string email);
		std::string getEmail();		
		
		Student& setAddress(std::string address);
		std::string getAddress();
		
		Student& setHighestCourse(unsigned short int highestCourse);
		unsigned short int getHighestCourse();
		
		Student& setGroupNumber(unsigned int groupNumber);
		unsigned int getGroupNumber();
		
		Student& setBirthAt(tm birthAt);
		// overloaded function for unix time
		Student& setBirthAt(time_t birthAt);
		tm getBirthAt();
		// returns in unix's time
		time_t getBirthAtUnix();
		
		Student& setIsLeader(bool isLeader);
		bool getIsLeader();

};	

#endif
