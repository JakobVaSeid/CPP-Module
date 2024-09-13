#include "ClapTrap.hpp"

int main (void){
    ClapTrap Robot("Roby");
    ClapTrap Machine("Machy");

    Robot.attack("Machy");
    Machine.takeDamage(5);
    Machine.beRepaired(10);
    Machine.attack("Roby");
    Robot.takeDamage(10);
    Robot.beRepaired(10);
    Robot.attack("Machy");
    Machine.takeDamage(10);
    Machine.beRepaired(10);
    Machine.attack("Roby");
    Robot.takeDamage(10);
    Robot.beRepaired(10);
}