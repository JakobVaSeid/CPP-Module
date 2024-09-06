/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:58:23 by jseidere          #+#    #+#             */
/*   Updated: 2024/08/28 12:04:55 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{   
    Zombie* zombie = newZombie("Felix");
    zombie->announce();
    randomChump("Chris");
    delete zombie;
    return (0);
}