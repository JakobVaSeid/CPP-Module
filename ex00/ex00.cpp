/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:02:11 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/26 17:26:00 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{

    for(int i = 1; i < argc; i++)
    {
        std::string argu = argv[i];
    for(std::string::iterator it = argu.begin(); it != argu.end(); it++)
    {    
        *it = std::toupper(*it);
    }   
        std::cout << argu;
    }
    std::cout << std::endl;

    return (0);
}