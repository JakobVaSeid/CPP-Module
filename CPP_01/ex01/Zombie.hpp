/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:21:50 by jseidere          #+#    #+#             */
/*   Updated: 2024/08/02 15:11:07 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie{
    
private:
    std::string name;
    
public:
    Zombie(){};
    Zombie(std::string Name){
        name = Name;
    }
    void announce(void);
    ~Zombie(){
        std::cout << "Killed Zombie: " << name << std::endl;
    }
    void setName(std::string Name)
    {
        this->name = Name;
    }
};
    Zombie* newZombie(std::string name);
    void randomChump (std::string name);
    Zombie* zombieHorde(int N, std::string name);

