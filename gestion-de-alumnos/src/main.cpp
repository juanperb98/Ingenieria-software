#include <stdio.h>
#include <iostream>

#include "funcionesAuxiliares.hpp"
#include "Classroom.hpp"
#include "Student.hpp"




int main(void)
{
	Classroom clase;
	Teacher juan;
	juan.setClassroom(clase);
	juan.setDni("123");
	juan.setName("Juan");
	juan.setRol("colaborador");

	
	menu(juan);

	return 0;
}
