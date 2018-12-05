/* src/Controller/DBController.hpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * Headers of the sysmtem's DBController
 */
 

#ifndef __DBCONTROLLER__
#define __DBCONTROLLER__

#include <string>
#include <stdio.h>
#include <fstream>
#include <unistd.h>
#include "Classroom.hpp"
#include "errorCodes.hpp"
#include "DBControllerErrorCodes.hpp"

class DBController{
	private:
		std::string _filePath;
	public:
		DBController(std::string path);
		
		std::string getPath();
		
		int save(Classroom classroom);
		int load(Classroom* classroom);
		
		int clear();
};

#endif