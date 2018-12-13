/* src/Controller/ExporterController/ExporterController.hpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * Headers of the sysmtem's ExporterController
 *
 * This class expoets a student to an html
 * file and launches firefox if it is set
 */

 
#ifndef __EXPORTERCONTROLLER__
#define __EXPORTERCONTROLLER__

#include <string>
#include <fstream>
#include <unistd.h>
#include "ExporterControllerErrorCodes.hpp"
#include "Student.hpp"
#include "errorCodes.hpp"
#include "ExporterControllerErrorCodes.hpp"


class ExporterController{
	private:
		std::string _basePath;
	public:
		ExporterController(std::string basePath);
		std::string getBasePath()const;
		int exportStudent(Student const & student)const;
		int clear(Student const & student)const;
};

#endif