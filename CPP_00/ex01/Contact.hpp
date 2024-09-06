#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdio.h>

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

#endif