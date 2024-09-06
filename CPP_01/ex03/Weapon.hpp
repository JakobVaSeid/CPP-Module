#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon{
private:
    std::string type;

public:
    Weapon(){};
    Weapon(std::string str){
        type = str;
    }
    void setType (std::string str);
    std::string getType (void);
};

#endif