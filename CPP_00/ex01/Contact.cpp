#include "Contact.hpp"

void Contact::readline(std::string &str, std::string msg){
    str.clear();
    while(str.empty() && !std::cin.eof())
    {
        std::cout << msg;
        std::getline(std::cin, str);
    }
}

void Contact::add_contact(int i){
    index = i;

    readline(first_name, "First name: ");
    readline(last_name, "Last name: ");
    readline(nick_name, "Nick name: ");
    readline(phone_number, "Phone number: ");
    readline(darkest_secret, "Darkest secret: ");
    std::cout << std::endl;
}
    
void Contact::giveInfos(){
    std::cout << "Index: " << index << std::endl;
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nick Name: " << nick_name << std::endl;
    std::cout << "Phonenumber: " << phone_number << std::endl;
    std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

void Contact::norm_contact(std::string str){
    size_t pos = 0;
    while((pos = str.find('\t', pos)) != std::string::npos){
        str.replace(pos, 1, "    ");
        pos += 4;
    }

    if(str.length() > 9)
        std::cout << std::right << std::setw(9) << str.substr(0, 9) << ".";
    else
        std::cout << std::right  << std::setw(10) << str;
    std::cout << "|";
}

void Contact::print_infos()
{
    std::cout << std::right  << std::setw(10) << index << "|";
    norm_contact(first_name);
    norm_contact(last_name);
    norm_contact(nick_name);
    std::cout << std::endl;
}