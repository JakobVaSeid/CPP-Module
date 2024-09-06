#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &Weapon){
    weapon = &Weapon;
}
void HumanB::attack(){
    if(weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon!" << std::endl;    
}