/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ex01.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:17:39 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/26 16:56:59 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
//using namespace std;

int main (int argc, char **argv)
{

    std::string argu = *argv;
    std::list<int> allPlayers = {2, 9, 7, 3,1,4,8,3,2,9};

    std::list<int> beginners; //rating 1-5
    std::list<int> pros;    //rating 6-10

    for(std::list<int>::iterator it = allPlayers.begin(); it!=allPlayers.end(); it++)
    {
        int rating = *it;
        if(rating >= 1 && rating <= 5)
            beginners.push_back(rating);
        else if(rating >= 6 && rating <= 10)
            pros.push_back(rating);
    }
    
    return (0);
    std::cin.get();
}