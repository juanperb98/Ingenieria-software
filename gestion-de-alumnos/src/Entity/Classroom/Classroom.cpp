/* src/Entity/Classroom/Classroom.cpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *	Hector Romero Lopez
 *
 * Sorce code for Classroom class
 */

#include "Classroom.hpp"

std::vector<Student> Classroom::getStudents()const{
	return students_;

}

int Classroom::addStudent(Student const & student){		
	for (size_t i = 0; i < getStudents().size(); i++) {
		if ( unlikely(student.getId()==students_[i].getId()) )
			return CLASSROOM_DUPLICATED_STUDENT;
	}

	return __addStudent(student);
}

int Classroom::__addStudent(Student const & student){
	if ( unlikely(this->getStudents().size() >= 150) )
		return CLASSROOM_FULL;
		
	students_.push_back(student);

	return SUCCESS;
}

int Classroom::deleteStudent(Student const & student){
	std::vector<Student>::iterator it;

	for (it = this->students_.begin(); it != this->students_.end(); it++) {
		if ( unlikely(student.getId() == it->getId()) ){
			this->students_.erase(it);
			return SUCCESS;
		}
	}
	return CLASSROOM_STUDENT_NOT_FOUND;
}




int Classroom::searchStudent(Student const & student,
			     std::vector<Student> &students)const{
	// loads all the students in the vector
	students = this->getStudents();
	
	//filters out the non matching students
	std::vector<Student>::iterator studentIterator;
	std::string regexPattern;
	
	if ( unlikely(students.size() == 0) )
		return CLASSROOM_EMPTY;
	
	for ( studentIterator = students.begin(); studentIterator != students.end(); studentIterator++ ){
		
		//set up the regexs
		regexPattern = ".*("+student.getId()+").*";
		std::regex idRegex(regexPattern);
		regexPattern = ".*("+student.getName()+").*";
		std::regex nameRegex(regexPattern);
		regexPattern = ".*("+student.getLastName()+").*";
		std::regex lastNameRegex(regexPattern);
		
		
		// if field is defined and not match, erase it
		if ( student.getId() != "" 
		&& ( unlikely(!std::regex_match(studentIterator->getId(), idRegex))) )
			students.erase(studentIterator);
		
		if ( student.getName() != "" 
		&& ( unlikely(!std::regex_match(studentIterator->getName(), nameRegex))) )
			students.erase(studentIterator);
			
		if ( student.getLastName() != "" 
		&& ( unlikely(!std::regex_match(studentIterator->getLastName(), lastNameRegex))) )
			students.erase(studentIterator);
	}
	
	return SUCCESS;
}


int Classroom::modifyStudent(Student const & target, Student const & newData){
	std::vector<Student> students;
	this->searchStudent(target, students);
	
	// checks for search errors, only one student must be found
	if ( students.size() == 0 )
		return CLASSROOM_STUDENT_NOT_FOUND;
	if ( students.size() > 1 )
		return CLASSROOM_MULTIPLES_OCURRENCES;
	
	Student student = students[0];
	
	this->deleteStudent(students[0]);
	
	if ( newData.getId() != "" )
		student.setId(newData.getId());
	
	if ( newData.getName() != "" )
		student.setName(newData.getName());
	
	if ( newData.getLastName() != "" )
		student.setLastName(newData.getLastName());
	
	if ( newData.getPhone() != 0 )
		student.setPhone(newData.getPhone());
	
	if ( newData.getEmail() != "" )
		student.setEmail(newData.getEmail());
	
	if ( newData.getAddress() != "" )
		student.setAddress(newData.getAddress());
		
	if ( newData.getHighestCourse() != 0 )
		student.setHighestCourse(newData.getHighestCourse());
		
	if ( newData.getGroupNumber() != 0 )
		student.setGroupNumber(newData.getGroupNumber());
		
	if ( newData.getBirthAtUnix() != 0 )
		student.setBirthAt(newData.getBirthAtUnix());
		
	student.setIsLeader(newData.getIsLeader());
	
	this->addStudent(student);
	
	return SUCCESS;
}


int Classroom::simpleModifyStudent(Student const & target, Student const & newData){
	std::vector<Student> students;
	this->searchStudent(target, students);
	
	// checks for search errors, only one student must be found
	if ( students.size() == 0 )
		return CLASSROOM_STUDENT_NOT_FOUND;
	if ( students.size() > 1 )
		return CLASSROOM_MULTIPLES_OCURRENCES;
	
	Student student = students[0];
	
	this->deleteStudent(students[0]);
	
	if ( newData.getId() != "" )
		student.setId(newData.getId());
	
	if ( newData.getName() != "" )
		student.setName(newData.getName());
	
	if ( newData.getLastName() != "" )
		student.setLastName(newData.getLastName());
	
	if ( newData.getPhone() != 0 )
		student.setPhone(newData.getPhone());
	
	if ( newData.getEmail() != "" )
		student.setEmail(newData.getEmail());
	
	if ( newData.getAddress() != "" )
		student.setAddress(newData.getAddress());
		
	if ( newData.getHighestCourse() != 0 )
		student.setHighestCourse(newData.getHighestCourse());
		
	if ( newData.getGroupNumber() != 0 )
		student.setGroupNumber(newData.getGroupNumber());
		
	if ( newData.getBirthAtUnix() != 0 )
		student.setBirthAt(newData.getBirthAtUnix());
			
	this->addStudent(student);
	
	return SUCCESS;
}
