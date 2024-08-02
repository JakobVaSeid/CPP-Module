/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:21:50 by jseidere          #+#    #+#             */
/*   Updated: 2024/08/02 12:51:04 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie{
    
private:
    std::string name;
    
public:
    Zombie(std::string Name){
        name = Name;
    }
    void announce(void);
    ~Zombie(){
        std::cout << "Killed Zombie: " << name << std::endl;
    }
};
    Zombie* newZombie(std::string name);
    void randomChump (std::string name);

