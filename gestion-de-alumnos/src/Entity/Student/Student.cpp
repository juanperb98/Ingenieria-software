/* src/Entity/Student/Student.cpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * Sorce code for Student class
 * This class should be used in a array of students
 * in the class 'classroom'
 */


#include "Student.hpp"


int Student::setId(std::string id){
	this->_id = id;
	return SUCCESS;
}

std::string Student::getId(){
	return _id;
};

int Student::setName(std::string name){
	this->_name = name;
	return SUCCESS;
}

std::string Student::getName(){
	return _name;
};

int Student::setLastName(std::string lastName){
	this->_lastName = lastName;
	return SUCCESS;
}

std::string Student::getLastName(){
	return _lastName;
};

int Student::setPhone(int phone){
	if ( unlikely(phone < 100000000) )
		return STUDENT_INVALID_PHONE;
		
	this->_phone = phone;
	return SUCCESS;
}

int Student::getPhone(){
	return _phone;
};

int Student::setEmail(std::string email){
	/* Reget to check if the email is semanticly valid
	 *
	 * diego@uco.es is valid
	 * @uco.es is not
	 * diego.es is not
	 * diego@uco is not
	 * diego@uco. is not
	 */
	std::regex emailRegex{"([[:alnum:]]+)@([[:alnum:]]+)[.]([[:alnum:]]+)$"};
	
	// if not match
	if ( unlikely(!(std::regex_match(email, emailRegex))) )
		return STUDENT_INVALID_EMAIL;
		
	this->_email = email;
	return SUCCESS;
}

std::string Student::getEmail(){
	return _email;
};

int Student::setAddress(std::string address){
	this->_address = address;
	return SUCCESS;
}

std::string Student::getAddress(){
	return _address;
};


int Student::setHighestCourse(unsigned short int highestCourse){
	this->_highestCourse = highestCourse;
	return SUCCESS;
}

unsigned short int Student::getHighestCourse(){
	return _highestCourse;
};


int Student::setGroupNumber(unsigned int groupNumber){
	this->_groupNumber = groupNumber;
	return SUCCESS;
}

unsigned int Student::getGroupNumber(){
	return _groupNumber;
};


int Student::setBirthAt(tm birthAt){
	// converts from tm to unix time
	time_t newDate = mktime(&birthAt);
	
	// if unix time is negative
	if ( unlikely(newDate == -1) )
		return STUDENT_INVALID_DATE;
		
	this->_birthAt = newDate;
	return SUCCESS;
}

// overloaded function for unix time
int Student::setBirthAt(time_t birthAt){
	// if unix time is negative
	if ( birthAt < 0 )
		return STUDENT_INVALID_DATE;
	this->_birthAt = birthAt;
	return SUCCESS;
}

tm Student::getBirthAt(){
	// convets from unix time to tm struct and returns it
	return *localtime(&this->_birthAt);
}

time_t Student::getBirthAtUnix(){
	return this->_birthAt;
}

int Student::setIsLeader(bool isLeader){
	this->_isLeader = isLeader;
	return SUCCESS;
}

bool Student::getIsLeader(){
	return _isLeader;
};


