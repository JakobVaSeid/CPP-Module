#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap:public ClapTrap{
    public:
    ScavTrap(std::string Name);
    ScavTrap(const ScavTrap &b);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();
    
    void guardGate();
};

#endif