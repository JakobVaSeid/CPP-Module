/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:29:10 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/30 17:50:42 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main ()
{
    std::string input;
    Phonebook phonebook;
    static int index = 0;

    while(true)
    {
        std::getline(std::cin, input);
        if(input == "ADD")
            phonebook.createContact(index++);
        else if(input == "SEARCH")
        {
            if(index < 1)
            {
                std::cout << "No contact available" << std::endl;
                continue;
            }
            phonebook.displayContact(index);
            std::cout << "Enter index: ";
            std::getline(std::cin, input);
            int num = atoi(input.c_str());
            phonebook.findContact(num);
        }
        else if(input == "EXIT")
            break;
        else
            std::cout << "Wrong input!" << std::endl;
    }
    return (0);
}
