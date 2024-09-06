#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target){
    std::cout << "ClapTrap " << this->_name << "attacks " << target << " causing " << this->_attackDmg << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout << "ClapTrap " << this->_name << " gets " << amount << " of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    std::cout << "ClapTrap " << this->_name << " repairs its self by " << amount << " points!" << std::endl;
}

ClapTrap::ClapTrap(std::string Name){
    std::cout << "Constructor with Name called" << std::endl;
    this->_name = Name;
    this->_hitPoints = 10;
    this->_engergyPoints = 10;
    this->_attackDmg = 0;
}

ClapTrap::ClapTrap(const ClapTrap &b){
    std::cout << "Copy-constructor" << std::endl;
    *this = b;
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor called!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    if(this != &other){
    this->_hitPoints = other._hitPoints;
    this->_engergyPoints = other._engergyPoints;
    this->_attackDmg = other._attackDmg;
    }
    return (*this);
}