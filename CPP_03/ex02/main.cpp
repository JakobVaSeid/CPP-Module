#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void){
    ClapTrap Robot("Roby");
    ClapTrap Machine("Machy");

    Robot.attack("Machy");
    Machine.takeDamage(10);
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

    ScavTrap newRobot("Newbie");

    ScavTrap copy(newRobot);

    newRobot.attack("Klaus");
    newRobot.takeDamage(10);
    newRobot.guardGate();
    newRobot.beRepaired(10);

    FragTrap fragTrap("Norbert");

    fragTrap.attack("Newbie");
    fragTrap.takeDamage(10);
    fragTrap.highFivesGuys();
    fragTrap.beRepaired(10);


}