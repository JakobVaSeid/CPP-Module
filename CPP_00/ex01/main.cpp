/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:29:10 by jseidere          #+#    #+#             */
/*   Updated: 2024/08/15 13:10:01 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    std::string input;
    Phonebook phonebook;
    static int index = 0;
    
    while(!std::cin.eof())
    {
        input.clear();
        while(input.empty() && !std::cin.eof())
        {
            std::getline(std::cin, input);
        }
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
            if(input.length() == 1 && isdigit(input[0]))
            {
                int num = input[0] - '0';
                phonebook.findContact(num, index);
            }
            else if (!std::cin.eof())
                std::cout << "Invalid index!" << std::endl;
        }
        else if(input == "EXIT")
            break;
        else if (!std::cin.eof())
            std::cout << "Wrong input!" << std::endl;
    }
    return (0);
}
