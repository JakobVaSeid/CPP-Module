#include "HumanA.hpp"

void HumanA::setWeapon(Weapon Weapon){
        weapon = Weapon;
    }
void HumanA::attack(){
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}