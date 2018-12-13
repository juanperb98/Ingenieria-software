#include <stdio.h>
#include <iostream>
#include "Classroom.hpp"
#include "Student.hpp"
#include "ExporterController.hpp"
int main ()
{
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

	ExporterController exporter("./output");
	exporter.clear(s1);
	exporter.exportStudent(s1);
}
