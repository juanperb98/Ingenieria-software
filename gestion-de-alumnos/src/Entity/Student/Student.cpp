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


Student& Student::setId(std::string id){
	this->_id = id;
	return *this;
}

std::string Student::getId(){
	return _id;
};

Student& Student::setName(std::string name){
	this->_name = name;
	return *this;
}

std::string Student::getName(){
	return _name;
};

Student& Student::setLastName(std::string lastName){
	this->_lastName = lastName;
	return *this;
}

std::string Student::getLastName(){
	return _lastName;
};

Student& Student::setPhone(int phone){
	this->_phone = phone;
	return *this;
}

int Student::getPhone(){
	return _phone;
};

Student& Student::setEmail(std::string email){
	this->_email = email;
	return *this;
}

std::string Student::getEmail(){
	return _email;
};

Student& Student::setAddress(std::string address){
	this->_address = address;
	return *this;
}

std::string Student::getAddress(){
	return _address;
};


Student& Student::setHighestCourse(unsigned short int highestCourse){
	this->_highestCourse = highestCourse;
	return *this;
}

unsigned short int Student::getHighestCourse(){
	return _highestCourse;
};


Student& Student::setGroupNumber(unsigned int groupNumber){
	this->_groupNumber = groupNumber;
	return *this;
}

unsigned int Student::getGroupNumber(){
	return _groupNumber;
};


Student& Student::setBirthAt(tm birthAt){
	this->_birthAt = mktime(&birthAt);
	return *this;
}

// overloaded function for unix time
Student& Student::setBirthAt(time_t birthAt){
	this->_birthAt = birthAt;
	return *this;
}

tm Student::getBirthAt(){
	return *localtime(&this->_birthAt);
}

time_t Student::getBirthAtUnix(){
	return this->_birthAt;
}

Student& Student::setIsLeader(bool isLeader){
	this->_isLeader = isLeader;
	return *this;
}

bool Student::getIsLeader(){
	return _isLeader;
};


