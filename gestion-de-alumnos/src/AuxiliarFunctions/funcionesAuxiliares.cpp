/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal 
  \author Juan Pedro Ruiz Bajo
  \date   
*/

// Para usar atoi


#include "funcionesAuxiliares.hpp"

int mostrarMenu() 
{
	char error = 0;
	int opcion = 0;
	
	// Se borra la pantalla
	
	do
	{
		std::cout << CLEAR_SCREEN;
		std::cout << "**********************************************\n"
				  << "*************** MENU *************************\n"
				  << "**********************************************\n"
				  << "** 1. Añadir Alumno                        ***\n"
				  << "** 2. Buscar Alumno                        ***\n"
				  << "** 3. Modificar Alumno                     ***\n"
				  << "** 4. Eliminar  Alumno                     ***\n"
				  << "** 5. Exportar información del alumno      ***\n"
				  << "** 6. Exportar copias de seguridad         ***\n"
				  << "** 7. Importar copias de seguridad         ***\n"
				  << "** 8. Mostrar  Alumno/s                     ***\n"
				  << "**********************************************\n"
				  << "** 0. Salir                                ***\n"
				  << "**********************************************\n";
				 
		std::cin >> opcion;
		std::cin.ignore();
		
		if (opcion < 0 || opcion > 8) 
		{
			std::cout << "ERROR: opcion incorrecta!!" << std::endl << "Pulsa intro para nueva opcion...";
			std::cin.get(error);
			
		}
		
	}while(opcion < 0 || opcion > 8);
	
	return opcion;
}


int menu(Classroom &classroom)
{
	int opcion = 0;
	int posicion = 0;

	while ( (opcion = mostrarMenu()) != 0)
	{	
		switch(opcion) {				
			case 1:
				// añadir alumno
				if(!addStudent(classroom)){
					std::cout << "Alumno añadido" << std::endl;
				}
				break;
			case 4:
				if(deleteStudent(classroom) == SUCCESS) 
				{
					std::cout << "Alumno eliminado" << std::endl;
				}
				break;
			
		}
	}

	/*PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Añadir Alumno";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Buscar alumno";

	PLACE(posicion++,10);
	std::cout << "[3] Modificar alumno";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,10);
	std::cout << "[4] Borrar alumno";

	PLACE(posicion++,10);
	std::cout <<  "[5] Exportar información del alumno";

	PLACE(posicion++,10);
	std::cout << "[6] Exportar copias de seguridad";

	PLACE(posicion++,10);
	std::cout << "[7] Importar copias de seguridad";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[8] Monstrar alumno/os";


	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;*/
}


//////////////////////////////////////////////////////////////////////////////

int addStudent(Classroom &classroom)
{
	std::cout << "Introduce los datos para el nuevo alumno: "  << std::endl;
	Student s1;
	time_t date = time(nullptr);
	
	
	std::string id = "";
	int leader = 0;
	
	std::cout << "DNI: ";
	std::cin >> id;
	std::cin.ignore();
	s1.setId(id);
	
	s1.setName("pepe");
	s1.setLastName("perez");
	s1.setPhone(689111111);
	s1.setEmail("pepe@uco.es");
	s1.setAddress("calle de pepe");
	s1.setHighestCourse(3);
	s1.setGroupNumber(4);
	s1.setBirthAt(date);
	
	std::cin >> leader;
	if (leader != 0)
		s1.setIsLeader(true);
	else
		s1.setIsLeader(false);

	return classroom.addStudent(s1);
}

//////////////////////////////////////////////////////////////////////////////

void searchStudent()
{
	 std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;

	return;
}

void modifyStudent(Classroom &classroom)
{
	Student oldStudent, newStudent;
	std::string nombre, dni;
	
	std::cout << "Id de alumno para modificar: " << std::endl;
	std::cin >> dni;
	std::cin.ignore();
	oldStudent.setId(dni);
	
	std::cout << "DNI: ";
	std::cin >> nombre;
	std::cin.ignore();
	newStudent.setName(nombre);
	
	

}

//////////////////////////////////////////////////////////////////////

int deleteStudent(Classroom &classroom)
{
	int opcion = -1;
	std::string apellidos = "";
	std::string dni = "";
	
	Student student;
	
	while (opcion < 0 || opcion > 1)
	{
		std::cout << "Pulse 1 para borrar por dni, pulse 2 para borrar por apellido: ";
		std::cin >> opcion;
		
		if (opcion == 1)
		{
			std::cout << "Id de alumno: " << std::endl;
			std::cin >> dni;
			std::cin.ignore();
			student.setId(dni);
		}
		else if (opcion== 0) {
			std::cin >> apellidos;
			std::cin.ignore();
			student.setLastName(apellidos);
		} else {
		 std::cout << "Opcion incorrecta!!" << std::endl;
		}
	}

	return classroom.deleteStudent(student);
}


//
void exportInformation()
{
	std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;

	return;
}


////////////////////////////////////////////////////////////////////////
void exportBackups()
{

std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;


	return;
}


void importBackups()
{
	std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;

	return;
}


void showStudent()
{
	std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;

	return;
}





