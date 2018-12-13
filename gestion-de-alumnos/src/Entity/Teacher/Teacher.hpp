#ifndef _Teacher_H_
#define _Teacher_H_
#include "errorCodes.hpp"
#include "DBController.hpp"
#include "Classroom.hpp"
#include <iostream>
#include <string>
class Teacher{
        private:
        std::string name_;
        std::string dni_;
        std::string rol_;
        Classroom classroom_;
        public:
         int setDni(std::string dni);
         std::string getDni()const;
         int setName(std::string dni);
         std::string getName()const;
         int setRol(std::string rol);
         std::string getRol()const;
         Classroom & getClassroom();
	void setClassroom(Classroom & classroom);
        int loadClassroom(std::string filePath);
        int saveClassroom(std::string filePath);
};

#endif
