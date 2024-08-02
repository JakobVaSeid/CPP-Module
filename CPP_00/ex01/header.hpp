/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:44:56 by jseidere          #+#    #+#             */
/*   Updated: 2024/08/01 12:50:53 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdio.h>

//index
//while loop
//private

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;

public:
    int index;
    void add_contact(int i);
    void giveInfos();
    void readline(std::string &str, std::string msg);
    void norm_contact(std::string str);
    void print_infos();
};

class Phonebook
{
private:
    Contact contact[8];
public:
    void createContact(int i);
    void findContact(int index, int counter);
    void displayContact(int index);
};