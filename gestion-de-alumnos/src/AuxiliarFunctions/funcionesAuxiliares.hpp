/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal 
  \date  
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Classroom.hpp"
#include "macros.hpp"
#include <string>
#include <stdlib.h>
#include <iostream>


  	int menu(Classroom &classroom);
  	int mostrarMenu();

	///////////////////////////////////////////////////////////////////


	int addStudent(Classroom &classroom);

	///////////////////////////////////////////////////////////////////


	void searchStudent();


	void modificateStudent();

	///////////////////////////////////////////////////////////////////


	int deleteStudent(Classroom &classroom);


	void exportInformation();

	///////////////////////////////////////////////////////////////////


	void exportBackups();


	void importBackups();


	///////////////////////////////////////////////////////////////////


	void showStudent();



	

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

