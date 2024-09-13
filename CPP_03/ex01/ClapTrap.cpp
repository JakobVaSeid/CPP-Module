#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target){
    if(this->_hitPoints > 0)
    {
        if(this->_engergyPoints > 0)
        {
            this->_engergyPoints--;
            std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDmg << " points of damage!" << std::endl;
        }
        else
            std::cout << "Not enough energy left!" << std::endl;
    }
    else
        std::cout << "I am dead, I can't do anything!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if(this->_hitPoints > 0)
    {
        if(this->_engergyPoints > 0)
        {
            this->_engergyPoints--;
            this->_hitPoints -= amount;
            std::cout << "ClapTrap " << this->_name << " gets " << amount << " of damage!" << std::endl;
        }
        else
            std::cout << "Not enough energy left!" << std::endl;
        if(this->_hitPoints <= 0)
            std::cout << this->_name << " died!" << std::endl;
    }
    else
        std::cout << "I am dead, I can't do anything!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if(this->_hitPoints > 0)
    {
        if(this->_engergyPoints > 0)
        {
            this->_engergyPoints--;
            this->_hitPoints += amount;
            std::cout << "ClapTrap " << this->_name << " repairs its self by " << amount << " points!" << std::endl;
        }
        else
            std::cout << "Not enough energy left!" << std::endl;
    }
    else
        std::cout << "I am dead, I can't do anything!" << std::endl;
}

ClapTrap::ClapTrap(std::string Name){
    std::cout << "ClapTrap-constructor with " << Name << " called" << std::endl;
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
    std::cout << "ClapTrap-destructor called!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    if(this != &other){
    this->_hitPoints = other._hitPoints;
    this->_engergyPoints = other._engergyPoints;
    this->_attackDmg = other._attackDmg;
    }
    return (*this);
}