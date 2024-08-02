#include "Weapon.hpp"

class HumanA{
private:
    std::string name;
    Weapon      weapon;
    
public:
    HumanA(std::string name, Weapon Weapon){
        
        weapon.setType();
    }
    void attack(){
        std::cout << name << " attacks with their " << weapon.getType() << std::endl;
    }
};