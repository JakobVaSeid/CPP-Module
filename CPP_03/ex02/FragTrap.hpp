#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
    FragTrap(std::string Name);
    FragTrap(const FragTrap &b);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    void highFivesGuys();
};

#endif