#include "Harl.hpp"

void Harl::debug(void){
    std::cout << "[ DEBUG ]:" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!!" << std::endl;
};

void Harl::info(void){
    std::cout << "[ INFO ]:" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
};

void Harl::warning(void){
    std::cout << "[ WARNING ]:" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
};

void Harl::error(void){
    std::cout << "[ ERROR ]:" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
};

void Harl::complain(std::string level){

    std::string strings[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    //void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    int i = 0;
    while(i < 4){
        if(level == strings[i])
            break;
        i++;
    }

    switch(i){
        case 0:
            debug();
            std::cout << std::endl;
        case 1:
            info();
            std::cout << std::endl;
        case 2:
            warning();
            std::cout << std::endl;
        case 3:
            error();
            break;
        default:
            std::cout << "Wrong Input, try:" << std::endl;
            std::cout << "DEBUG | INFO | WARNING | ERROR" << std::endl;
            break;
    }
};

            