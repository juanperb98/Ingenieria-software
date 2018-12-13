#ifndef _Teacher_H_
#define _Teacher_H_
#include "errorCodes.hpp"
#include "DBController.hpp"
#include "Classroom.hpp"
#include <iostream>
class Teacher{
        private:
        std::string nombre_;
        std::string dni_;
        std::string rol_;
        Classroom & classroom_;
        public:
        inline int setDni(std::string dni);
        inline std::string getDni()const;
        inline int setRol(std::string rol);
        inline std::string getRol()const;
        inline Classroom & getClassrooom();
	void setClassrooom(Classroom & classroom);
        int loadClassroom(std::string filePath);
        int saveClassroom(std::string filePath);
};

#endif
