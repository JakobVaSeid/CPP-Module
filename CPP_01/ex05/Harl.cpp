#include "Harl.hpp"

void Harl::debug(void){
    std::cout << "Debugging!" << std::endl;
};

void Harl::info(void){
    std::cout << "Info!" << std::endl;
};

void Harl::warning(void){
    std::cout << "Warning!" << std::endl;
};

void Harl::error(void){
    std::cout << "Error!" << std::endl;
};

void Harl::complain(std::string level){

    std::string strings[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    for(int i = 0; i < 4; i++){
        if(level == strings[i]){
            std::cout << strings[i] << ": ";
            (this->*functions[i])();
        }
    }
};
