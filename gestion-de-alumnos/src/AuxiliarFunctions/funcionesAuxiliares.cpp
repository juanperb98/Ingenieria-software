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


int menu(Teacher & teacher)
{
	int opcion = 0;
	int posicion = 0;
	
	while ( (opcion = mostrarMenu()) != 0)
	{	
		switch(opcion) {				
			case 1:
				// añadir alumno
				addStudent(teacher.getClassroom());
				break;
				
			case 2:
				searchStudent(teacher.getClassroom());		
				break;
			
			case 3:
				modifyStudent(teacher.getClassroom());
				break;
				
			case 4:
				deleteStudent(teacher.getClassroom());
				break;
				
			case 5:
				exportInformation(teacher.getClassroom());
				break;
				
			case 6:
				exportBackup(teacher);
				break;
				
			case 7:
				importBackup(teacher);
				break;			
		}
	}

}

//////////////////////////////////////////////////////////////////////////////

int addStudent(Classroom &classroom)
{
	std::cout << "Introduce los datos para el nuevo alumno: "  << std::endl;
	Student s1;
	char aux[255];
	
	std::string id = "";
	
	std::cout << "DNI: ";
	std::cin.getline(aux,255);
	id=aux;
	s1.setId(id);
	
	std::string name = "";
	std::cout << "Nombre: ";
	std::cin.getline(aux,255);
	name=aux;
	s1.setName(name);
	
	std::string apellido = "";
	std::cout << "Apellidos: ";
	std::cin.getline(aux,255);
	apellido=aux;
	s1.setLastName(apellido);
	
	int phone = 0;
	std::cout << "Teléfono: ";
	std::cin.getline(aux,255);
	phone=atoi(aux);
	while ( s1.setPhone(phone) ){
		std::cout << "Teléfono invalido, introduzca otro\n";
		std::cout << "Teléfono: ";
		std::cin.getline(aux,255);
		phone=atoi(aux);
	}
	
	std::string email = "";
	std::cout << "Email: ";
	std::cin.getline(aux,255);
	email=aux;

	while (s1.setEmail(email) ){
		std::cout << "Correo invalido, introduzca otro\n";
		std::cout << "Email: ";
		std::cin.getline(aux,255);
		email=aux;
	}
	
	
	std::string calle = "";
	std::cout << "Dirección: ";
	std::cin.getline(aux,255);
	calle=aux;
	s1.setAddress(calle);

	
	int curso = 0;
	std::cout << "Curso mas alto: ";
	std::cin.getline(aux,255);
	curso=atoi(aux);
	s1.setHighestCourse(curso);
	
	
	int grupo = 0;
	std::cout << "Numero de grupo: ";
	std::cin.getline(aux,255);
	grupo=atoi(aux);
	s1.setGroupNumber(grupo);
	
	tm date;
	std::cout << "Año: ";
	std::cin.getline(aux,255);
	date.tm_year=atoi(aux);
	std::cout << "Mes ";
	std::cin.getline(aux,255);
	date.tm_mon=atoi(aux);
	std::cout << "Dia ";
	std::cin.getline(aux,255);
	date.tm_mday=atoi(aux);
	while (s1.setBirthAt(date) ){
		std::cout << "Fecha invalida, introduzca otra\n";
		std::cout << "Año: ";
		std::cin.getline(aux,255);
		date.tm_year=(atoi(aux)-1);
		std::cout << "Mes ";
		std::cin.getline(aux,255);
		date.tm_mon=(atoi(aux)-1);
		std::cout << "Dia ";
		std::cin.getline(aux,255);
		date.tm_mday=(atoi(aux)-1);
	
	}
	
	std::cout << "es lider? [si,no]" << '\n';
	std::string leader;
	std::cin >> leader;
	if (leader == "si")
		s1.setIsLeader(true);
	else
		s1.setIsLeader(false);

	return classroom.addStudent(s1);
}

//////////////////////////////////////////////////////////////////////////////

void searchStudent(Classroom &classroom)
{
	std::cout << "Introduzca los campos a aplicar la busqueda, is no desea aplicar filtro a un parametro, no lo rellene (presiona intro)" << std::endl;
	
	std::vector<Student> students;
	Student s1;
	char aux[255];
	
	std::string id = "";
	int leader = 0;
	
	std::cout << "DNI: ";
	std::cin.getline(aux,255);
	id=aux;
	s1.setId(id);
	
	std::string name = "";
	std::cout << "Nombre: ";
	std::cin.getline(aux,255);
	name=aux;
	s1.setName(name);
	
	std::string apellido = "";
	std::cout << "Apellidos: ";
	std::cin.getline(aux,255);
	apellido=aux;
	s1.setLastName(apellido);
	
	if (classroom.searchStudent(s1, students)){
		std::cout << "ERROR!" << '\n';
	}
	
	for (size_t i = 0; i<students.size();i++){
		showStudent(students[i]);
	}
	std::cin.getline(aux,255);

	return;
}

void modifyStudent(Classroom &classroom)
{
	std::cout << "Introduzca los campos a aplicar la busqueda, is no desea aplicar filtro a un parametro, no lo rellene (presiona intro)" << std::endl;
	
	std::vector<Student> students;
	Student s1;
	char aux[255];
	
	std::string id = "";
	int leader = 0;
	
	std::cout << "DNI: ";
	std::cin.getline(aux,255);
	id=aux;
	s1.setId(id);
	
	std::string name = "";
	std::cout << "Nombre: ";
	std::cin.getline(aux,255);
	name=aux;
	s1.setName(name);
	
	std::string apellido = "";
	std::cout << "Apellidos: ";
	std::cin.getline(aux,255);
	apellido=aux;
	s1.setLastName(apellido);
	
	if (classroom.searchStudent(s1, students)){
		std::cout << "ERROR!" << '\n';
	}
	
	for (size_t i = 0; i<students.size();i++){
		std::cout <<i<<") "<<students[i].getId()<<", "<<students[i].getName()<<", "<<students[i].getLastName()<<"\n";
	}
	std::cout << "introdizca el alumno a modificar: " << '\n';
	std::cin.getline(aux,255);
	Student student = students[atoi(aux)];
	
	
	
	
	
	
	
	std::cout << "introduzca los nuevos datos:" << '\n';
	
	
	Student newdata;
	
	
	std::cout << "DNI: ";
	std::cin.getline(aux,255);
	id=aux;
	newdata.setId(id);
	
	std::cout << "Nombre: ";
	std::cin.getline(aux,255);
	name=aux;
	newdata.setName(name);
	
	std::cout << "Apellidos: ";
	std::cin.getline(aux,255);
	apellido=aux;
	newdata.setLastName(apellido);
	
	std::cout << "Teléfono: ";
	std::cin.getline(aux,255);
	int phone = atoi(aux);
	while ( newdata.setPhone(phone) ){
		std::cout << "Teléfono invalido, introduzca otro\n";
		std::cout << "Teléfono: ";
		std::cin.getline(aux,255);
		phone=atoi(aux);
	}
	
	std::cout << "Email: ";
	std::cin.getline(aux,255);
	std::string email=aux;

	while (newdata.setEmail(email) ){
		std::cout << "Correo invalido, introduzca otro\n";
		std::cout << "Email: ";
		std::cin.getline(aux,255);
		email=aux;
	}
	
	
	std::cout << "Dirección: ";
	std::cin.getline(aux,255);
	std::string calle=aux;
	newdata.setAddress(calle);

	
	std::cout << "Curso mas alto: ";
	std::cin.getline(aux,255);
	int curso=atoi(aux);
	newdata.setHighestCourse(curso);
	
	
	std::cout << "Numero de grupo: ";
	std::cin.getline(aux,255);
	int grupo=atoi(aux);
	newdata.setGroupNumber(grupo);
	
	
	tm date;
	std::cout << "Año: ";
	std::cin.getline(aux,255);
	date.tm_year=atoi(aux);
	std::cout << "Mes ";
	std::cin.getline(aux,255);
	date.tm_mon=atoi(aux);
	std::cout << "Dia ";
	std::cin.getline(aux,255);
	date.tm_mday=atoi(aux);
	while (newdata.setBirthAt(date) ){
		std::cout << "Fecha invalida, introduzca otra\n";
		std::cout << "Año: ";
		std::cin.getline(aux,255);
		date.tm_year=(atoi(aux)-1);
		std::cout << "Mes ";
		std::cin.getline(aux,255);
		date.tm_mon=(atoi(aux)-1);
		std::cout << "Dia ";
		std::cin.getline(aux,255);
		date.tm_mday=(atoi(aux)-1);
	
	}
	
	std::cout << "es lider? [si,no]" << '\n';
	std::cin.getline(aux,255);
	if (aux == "si")
		newdata.setIsLeader(true);
	else
		newdata.setIsLeader(false);
		
	
	
	
	
	
	
	if (classroom.modifyStudent(student,newdata))
		std::cout << "error!!" << '\n';
	else
		std::cout << "modificado con exito" << '\n';
	std::cin.getline(aux,255);
	return;

	

}

//////////////////////////////////////////////////////////////////////

void deleteStudent(Classroom &classroom)
{
	std::cout << "Introduzca los campos a aplicar la busqueda, is no desea aplicar filtro a un parametro, no lo rellene (presiona intro)" << std::endl;
	
	std::vector<Student> students;
	Student s1;
	char aux[255];
	
	std::string id = "";
	int leader = 0;
	
	std::cout << "DNI: ";
	std::cin.getline(aux,255);
	id=aux;
	s1.setId(id);
	
	std::string name = "";
	std::cout << "Nombre: ";
	std::cin.getline(aux,255);
	name=aux;
	s1.setName(name);
	
	std::string apellido = "";
	std::cout << "Apellidos: ";
	std::cin.getline(aux,255);
	apellido=aux;
	s1.setLastName(apellido);
	
	if (classroom.searchStudent(s1, students)){
		std::cout << "ERROR!" << '\n';
	}
	
	for (size_t i = 0; i<students.size();i++){
		std::cout <<i<<") "<<students[i].getId()<<", "<<students[i].getName()<<", "<<students[i].getLastName()<<"\n";
	}
	std::cout << "introdizca el alumno a modificar: " << '\n';
	std::cin.getline(aux,255);
	Student student = students[atoi(aux)];
	
	
	
	
	
	if (classroom.deleteStudent(student))
		std::cout << "error!!" << '\n';
	else
		std::cout << "modificado con exito" << '\n';
	std::cin.getline(aux,255);
	return;
}


//
void exportInformation(Classroom &classroom)
{
	std::cout << "Introduzca los campos a aplicar la busqueda, is no desea aplicar filtro a un parametro, no lo rellene (presiona intro)" << std::endl;
	
	std::vector<Student> students;
	Student s1;
	char aux[255];
	
	std::string id = "";
	int leader = 0;
	
	std::cout << "DNI: ";
	std::cin.getline(aux,255);
	id=aux;
	s1.setId(id);
	
	std::string name = "";
	std::cout << "Nombre: ";
	std::cin.getline(aux,255);
	name=aux;
	s1.setName(name);
	
	std::string apellido = "";
	std::cout << "Apellidos: ";
	std::cin.getline(aux,255);
	apellido=aux;
	s1.setLastName(apellido);
	
	if (classroom.searchStudent(s1, students)){
		std::cout << "ERROR!" << '\n';
	}
	
	for (size_t i = 0; i<students.size();i++){
		std::cout <<i<<") "<<students[i].getId()<<", "<<students[i].getName()<<", "<<students[i].getLastName()<<"\n";
	}
	std::cout << "introdizca el alumno a modificar: " << '\n';
	std::cin.getline(aux,255);
	Student student = students[atoi(aux)];
	
	
	char path[255];
	std::cout<<"Introduce la ruta para guardar el archivo"<<std::endl;
	std::cin.getline(path,255);
	
	ExporterController exporter(path);
	int error = exporter.exportStudent(student);
	switch (error) {
		case EXPORTERCONTROLLER_FILE_EXISTS:
		{
			
			std::cout << "el fichero existe, quieres borrarlo? [si, no]" << '\n';
			char option[255];
			std::cin.getline(path,255);
			if ( option == "si" ) {
				exporter.clear(student);
				exporter.exportStudent(student);
			}
			break;
		}
		default:
			std::cout << "error: " <<error<< '\n';
			
	}
	std::cout << "exportado con exito" << '\n';
	std::cin.getline(aux,255);
	return;
}

////////////////////////////////////////////////////////////////////////


void showStudent(Student student)
{
	std::cout<<"DNI: "<<student.getId()<<"\n"
	<<"Nombre: "<<student.getName()<<"\n"
	<<"Apellidos: "<<student.getLastName()<<"\n"
	<<"Teléfono: "<<student.getPhone()<<"\n"
	<<"Email: "<<student.getEmail()<<"\n"
	<<"Direccion: "<<student.getAddress()<<"\n"
	<<"Mayor curso matriculado: "
		<<student.getHighestCourse()<<"\n"
	<<"Grupo: "<<student.getGroupNumber()<<"\n"
	<<"Fecha de Nacimiento: "
		<<student.getBirthAt().tm_mday<<"-"
		<<student.getBirthAt().tm_mon<<"-"
		<<student.getBirthAt().tm_year<<"\n"
	<<"Es Lider? "<<(student.getIsLeader()==true ? "Si":"No")<<"\n";
	
	return;
}

void exportBackup(Teacher & teacher){
	char path[255];
	std::cout<<"Introduce la ruta para guardar el archivo"<<std::endl;
	std::cin.getline(path,255);
	Classroom classroom = teacher.getClassroom();
	DBController controlador(path);
	int saveStatus  = controlador.save(classroom);
	if (saveStatus ==  DBCONTROLLER_PERMISSION_DENIED ){
		std::cout<<"Permiso denegado para escribir"<<std::endl;		
		exportBackup(teacher);
	}
	else if(saveStatus ==DBCONTROLLER_INVALID_PATH){
		std::cout<<"Ruta para el archivo incorrecta"<<std::endl;
		exportBackup(teacher);
	}
	else if (saveStatus == DBCONTROLLER_FILE_EXISTS){
		std::cout<<"El archivo existe"<<std::endl;
		exportBackup(teacher);
	}
	else{
		teacher.setClassroom(classroom);
	}
}

void importBackup(Teacher & teacher){
	
	char path[255];
	std::cout<<"Introduce la ruta para cargar el archivo"<<std::endl;
	std::cin.getline(path,255);
	DBController controlador(path);
	Classroom & classroom = teacher.getClassroom();
	int saveStatus  = controlador.load(classroom);
	if (saveStatus == DBCONTROLLER_PERMISSION_DENIED ){
		std::cout<<"Permiso denegado para escribir"<<std::endl;		
		importBackup(teacher);
	}
	else if(saveStatus == DBCONTROLLER_INVALID_PATH){
		std::cout<<"Ruta para el archivo incorrecta"<<std::endl;
		importBackup(teacher);
	}
	else if (saveStatus == DBCONTROLLER_FILE_EXISTS){
		std::cout<<"El archivo existe"<<std::endl;
		importBackup(teacher);
	}
	else{
		teacher.setClassroom(classroom);
	}
}



