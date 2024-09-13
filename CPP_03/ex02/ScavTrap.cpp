#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name):ClapTrap( Name){
    _name = Name;
    _hitPoints = 100;
    _engergyPoints = 50;
    _attackDmg = 20;
    std::cout << "ScavTrap-destructor with " << this->_name << " has been created!" << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << this->_name << " is guarding the gate!" << std::endl; 
}

ScavTrap::ScavTrap(const ScavTrap &b):ClapTrap(b){
    std::cout << "ScavTrap-Copy-constructor" << std::endl;
    *this = b;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
    if(this != &other){
    this->_hitPoints = other._hitPoints;
    this->_engergyPoints = other._engergyPoints;
    this->_attackDmg = other._attackDmg;
    }
    return (*this);
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap-destructor called!" << std::endl;
};