#include <stdio.h>
#include <iostream>
#include "Entity/Classroom/Classroom.hpp"
#include "Entity/Student/Student.hpp"
int main ()
{
Classroom classroom;
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

Student s2;
s2.setId("1234");
s2.setName("juan");
s2.setLastName("lopez");
s2.setPhone(689112111);
s2.setEmail("juan@uco.es");
s2.setAddress("calle de juan");
s2.setHighestCourse(2);
s2.setGroupNumber(3);
s2.setBirthAt(date);
s2.setIsLeader(false);

Student s3;
s3.setId("");
s3.setName("");
s3.setLastName("");
std::vector<Student> vector1;
classroom.addStudent(s1);
classroom.addStudent(s2);
classroom.searchStudent(s2,vector1);
std::vector<Student>::iterator studentIterator;
for (studentIterator = vector1.begin();studentIterator != vector1.end();studentIterator++){
    std::cout<<studentIterator->getId();
  }
}
