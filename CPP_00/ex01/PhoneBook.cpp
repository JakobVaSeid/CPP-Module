/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:28:48 by jseidere          #+#    #+#             */
/*   Updated: 2024/08/15 12:57:07 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Phonebook::createContact(int i){
    i %= 8;
    contact[i].add_contact(i);
    return;
}
    
void Phonebook::findContact(int index, int counter){
    if(index < counter && contact[index].index == index)
        contact[index].giveInfos();
    else
        std::cout << "No contact found" << std::endl;
    return;
}

void Phonebook::displayContact(int index){
    std::cout << std::right << std::setw(10) << "Index" << "|";
    std::cout << std::right << std::setw(10) << "Firstname" << "|";
    std::cout << std::right << std::setw(10) << "Lastname" << "|";
    std::cout << std::right << std::setw(10) << "Nickname" << "|";
    std::cout << std::endl;
    if (index > 8)
        index = 8;
    for(int i = 0; i < index; i++)
        contact[i].print_infos();
}
