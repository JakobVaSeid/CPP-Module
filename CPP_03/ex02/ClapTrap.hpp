#ifndef CLAPPTRAPP_HPP
# define CLAPPTRAPP_HPP

#include <iostream>
#include <string>

class ClapTrap {
    protected:
        std::string _name;
        int _hitPoints;
        int _engergyPoints;
        int _attackDmg;
    public:
        ClapTrap(std::string Name);
        ClapTrap(const ClapTrap &b);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif