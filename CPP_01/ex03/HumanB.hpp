#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB{
private:
    std::string name;
    Weapon      *weapon;
    
public:
    HumanB(std::string Name) : name(Name), weapon(NULL){
    }
    void setWeapon(Weapon &Weapon);
    void attack();
};

#endif