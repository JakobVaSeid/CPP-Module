#include "Weapon.hpp"

void Weapon::setType (std::string str){
        this->type = str;
    }
std::string Weapon::getType (void){
    return (type);
}