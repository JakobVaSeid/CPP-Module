#include "FragTrap.hpp"

FragTrap::FragTrap(std::string Name):ClapTrap( Name){
    _name = Name;
    _hitPoints = 100;
    _engergyPoints = 100;
    _attackDmg = 30;
    std::cout << "FragTrap-destructor with " << this->_name << " has been created!" << std::endl;
}
void FragTrap::highFivesGuys(){
    std::cout << "FragTrap " << this->_name << " is giving high fives to the guys!" << std::endl; 
}

FragTrap::FragTrap(const FragTrap &b):ClapTrap(b){
    std::cout << "FragTrap-Copy-constructor" << std::endl;
    *this = b;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
    if(this != &other){
    this->_hitPoints = other._hitPoints;
    this->_engergyPoints = other._engergyPoints;
    this->_attackDmg = other._attackDmg;
    }
    return (*this);
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap-destructor called!" << std::endl;
};