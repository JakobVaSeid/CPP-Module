/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:41:15 by jseidere          #+#    #+#             */
/*   Updated: 2024/08/02 17:01:05 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (void)
{
    std::string a = "HI THIS IS BRAIN";
    std::string *b = &a;
    std::string &c = a;
    
    std::cout << "Adress STR: "<< &a << std::endl;
    std::cout << "Address strPTR: " << b << std::endl;
    std::cout << "Address strREF: " << &c << std::endl;
    std::cout << std::endl;
    std::cout << "String: " << a << std::endl;
    std::cout << "StrPTR: " << *b << std::endl;
    std::cout << "StrREF: "<< c << std::endl;
    
}