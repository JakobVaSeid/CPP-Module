/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:44:56 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/29 19:14:27 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <sstream>

class Contact
{
public:
    int         index;
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;
    
    //private:
    void add_contact(int i){
        index = i;
        while(true)
        {
            std::cout << "First Name: " << first_name;
            std::getline(std::cin, first_name);
            std::cout << "Last Name: " << last_name;
            std::getline(std::cin, last_name);
            std::cout << "Nick Name: " << nick_name;
            std::getline(std::cin, nick_name);
            std::cout << "Phonenumber: " << phone_number;
            std::getline(std::cin, phone_number);
            std::cout << "Darkest secret: " << darkest_secret;
            std::getline(std::cin, darkest_secret);
            std::cout << std::endl;
            break;
        }    
    }
    
    void giveInfos(){
    std::cout << "Index: " << index << std::endl;
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nick Name: " << nick_name << std::endl;
    std::cout << "Phonenumber: " << phone_number << std::endl;
    std::cout << "Darkest secret: " << darkest_secret << std::endl;
    }
};

class Phonebook
{
    Contact contact[8];
public: 
    void createContact(int i)
    {
        contact[i].add_contact(i);
    return;
    }
    void findContact(int index)
    {
            if(contact[index].index == index)
                contact[index].giveInfos();
            else
                std::cout << "No contact found" << std::endl;
    return;
    }
 
    
};