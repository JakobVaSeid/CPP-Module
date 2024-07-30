/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:44:56 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/30 17:50:32 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>

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
            //std::cin.clear();
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
        i %= 2;
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
    void norm_contact(std::string str){
        size_t len = str.length();
        if(len > 9)
            std::cout << std::right << std::setw(9) << str.substr(0, 8) << ".";
        else
            std::cout << std::right  << std::setw(10) << str;
        std::cout << "|";
    }
    void displayContact(int index)
    {
        std::cout << std::right  << std::setw(10) << "Index" << "|";
        std::cout << std::right  << std::setw(10) << "Firstname" << "|";
        std::cout << std::right  << std::setw(10) << "Lastname" << "|";
        std::cout << std::right  << std::setw(10) << "Nickname" << "|";
        std::cout << std::endl;
        for(int i = 0; i < index; i++)
        {
            std::cout << std::right  << std::setw(10) << contact[i].index << "|";
            norm_contact(contact[i].first_name);
            norm_contact(contact[i].last_name);
            norm_contact(contact[i].nick_name);
            std::cout << std::endl;
        }
    }
};