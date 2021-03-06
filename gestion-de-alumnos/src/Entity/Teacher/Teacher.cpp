#include "Teacher.hpp"

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
int Teacher::setPasswd(std::string passwd){
        passwd_ = passwd;
        return SUCCESS;
}
std::string Teacher::getPasswd()const{
        return passwd_;
}
int Teacher::setName(std::string rol){
        name_ = rol;
        return SUCCESS;
}
std::string Teacher::getName()const{
        return name_;
}
Classroom & Teacher::getClassroom(){
        return classroom_;
}
void Teacher::setClassroom(Classroom & classroom){
	classroom_=classroom;
}
int Teacher::loadClassroom(std::string filePath){
        DBController databaseController(filePath);
        return databaseController.load(classroom_);
}

int Teacher::saveClassroom(std::string filePath){
        DBController databaseController(filePath);
        return databaseController.save(classroom_);

}
