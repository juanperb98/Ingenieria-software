#include "accounts.hpp"

std::vector<Teacher> initializeAccounts(){
	std::vector<Teacher> teachers;

	Teacher pepe;
	pepe.setDni("123123123");
	pepe.setName("pepe");
	pepe.setPasswd("secret");
	pepe.setRol("ayudante");
	teachers.push_back(pepe);

	Teacher juan;
	juan.setDni("321312321");
	juan.setName("juan");
	juan.setPasswd("secret");
	juan.setRol("coordinador");
	teachers.push_back(juan);
	
	return teachers;
}
