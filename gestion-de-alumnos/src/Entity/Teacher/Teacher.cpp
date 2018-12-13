#include "Teacher.h"

int Teacher::setDni(std::string dni){
        dni_ = dni;
        return SUCCESS;
}
std::string Teacher::getDni()const{
        return dni_;
}
int Teacher::setRol(std::string rol){
        rol_ = rol;
        return SUCCESS;
}
std::string Teacher::getRol()const{
        return rol_;
}
Classroom Teacher::getClassrooom(){
        return classroom_;
}
int Teacher::loadClassroom(std::string filePath){
        DBController databaseController(filePath);
        return databaseController.load(classroom_);
}

int Teacher::saveClassroom(std::string filePath){
        DBController databaseController(filePath);
        return databaseController.save(classroom_);

}
