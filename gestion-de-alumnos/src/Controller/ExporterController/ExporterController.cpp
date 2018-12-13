/* src/Controller/ExporterController/ExporterController.cpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * Source code of the sysmtem's ExporterController
 */


#include "ExporterController.hpp"

ExporterController::ExporterController(std::string basePath):_basePath(basePath){}

std::string ExporterController::getBasePath()const{
	return _basePath;
}

int ExporterController::exportStudent(Student const & student)const{
	if ( getBasePath() == "" )
		return EXPORTERCONTROLLER_INVALID_PATH;
		
	// checks if file exist
	std::ifstream testFile;
	std::string path = this->getBasePath() + "/" + student.getId();
	
	
	testFile.open( path );
	if ( testFile.is_open() )
		return EXPORTERCONTROLLER_FILE_EXISTS;
	
	// if the file exists, close it and open it in wirte binary mode
	testFile.close();	
	std::ofstream file;


	file.open( path );

	
	// checks if it's open
	if ( !file.is_open() )
		return EXPORTERCONTROLLER_PERMISSION_DENIED;
	
	// writes the students to file
	
	file<<"<html><head><title>"
	<<student.getName() // bame to the title
	<<"</title></head><body>" // opens the body
	<<"<ul>\n" // set ups the list
		<<"<li>DNI: "<<student.getId()<<"</li>\n"
		<<"<li>Nombre: "<<student.getName()<<"</li>\n"
		<<"<li>Apellidos: "<<student.getLastName()<<"</li>\n"
		<<"<li>Teléfono: "<<student.getPhone()<<"</li>\n"
		<<"<li>Email: "<<student.getEmail()<<"</li>\n"
		<<"<li>Direccion: "<<student.getAddress()<<"</li>\n"
		<<"<li>Mayor curso matriculado: "
			<<student.getHighestCourse()<<"</li>\n"
		<<"<li>Grupo: "<<student.getGroupNumber()<<"</li>\n"
		<<"<li>Fecha de Nacimiento: "
			<<student.getBirthAt().tm_mday
			<<"-"
			<<student.getBirthAt().tm_mon+1
			<<"-"\
			<<student.getBirthAt().tm_year
		<<"</li>\n"
		<<"<li>Es Lider? "<<(student.getIsLeader()==true ? "Si":"No") <<"</li>\n"
	<<"</ul>" // closes the list
	<<"</body></html>\n";
	
	file.close();
	
	if( !fork() )
		execl("/usr/bin/firefox", "firefox", path.c_str(), (char *) 0);
	
	return SUCCESS;
}


int ExporterController::clear(Student const & student)const{
	if ( getBasePath() == "" )
		return EXPORTERCONTROLLER_INVALID_PATH;
		
	std::string path = this->getBasePath() + "/" + student.getId();
	
	if ( remove(path.c_str()) != 0 )
		return EXPORTERCONTROLLER_FILE_NOT_EXISTS;

	return SUCCESS;
}