#include <stdio.h>
#include <iostream>

#include "funcionesAuxiliares.hpp"
#include "Classroom.hpp"
#include "Student.hpp"
#include "accounts.hpp"




int main(void)
{
	std::vector<Teacher> teachers;
	teachers = initializeAccounts();


	char aux[255];
	
	std::cout << "introduzca las credenciales:\n\tlogin: ";
	std::cin.getline(aux,255);
	std::string login = aux;
	std::cout << "\tcontraseña: ";
	std::cin.getline(aux,255);
	std::string passwd = aux;
	
	for (size_t i = 0; i < teachers.size(); i++) {
		if (login == teachers[i].getName()
		&& passwd == teachers[i].getPasswd()) {
			std::cout << "bienvenido "<<teachers[i].getName()<<" eres "<<teachers[i].getRol()<<"!\n\n\npresiona intro para continuar";
			std::cin.getline(aux,255);
			menu(teachers[i]);
			return 0;
		}
	}
	
	std::cout << "login invalido!" << '\n';
	
	
	return 0;
}
