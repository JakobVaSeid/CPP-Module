/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:35:18 by jseidere          #+#    #+#             */
/*   Updated: 2024/08/02 15:38:02 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name){
    Zombie* zombie = new Zombie(name);
    return (zombie);
}

Zombie* zombieHorde(int N, std::string name){
   Zombie *horde = new Zombie[N];
   for(int i = 0; i < N; i++)
   {
    horde[i].setName(name);
    horde[i].announce();
   }
   return (horde);
}