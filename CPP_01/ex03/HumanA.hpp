#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP


#include "Weapon.hpp"

class HumanA{
private:
    std::string name;
    Weapon      &weapon;
    
public:
    HumanA(std::string Name, Weapon &Weapon) : name(Name), weapon(Weapon){
    }
    void setWeapon(Weapon Weapon);
    void attack();
};

#endif