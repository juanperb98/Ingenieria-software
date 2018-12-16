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
#include "Teacher.hpp"
#include "ExporterController.hpp"


	


  	int menu(Teacher & teacher);
  	int mostrarMenu();

	///////////////////////////////////////////////////////////////////


	int addStudent(Classroom &classroom);

	///////////////////////////////////////////////////////////////////


	void searchStudent(Classroom &classroom);


	void modifyStudent(Classroom &classroom);

	///////////////////////////////////////////////////////////////////


	void deleteStudent(Classroom &classroom);


	void exportInformation(Classroom &classroom);

	///////////////////////////////////////////////////////////////////




	void importBackup(Teacher & teacher);
	void exportBackup(Teacher & teacher);


	///////////////////////////////////////////////////////////////////


	void showStudent(Student student);



	

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

