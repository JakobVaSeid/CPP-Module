#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal-constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &b){
    std::cout << "Copy-constructor WrongAnimal!" << std::endl;
    *this = b;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal-destructor called!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    if(this != &other){
    this->type = other.type;
    }
    return (*this);
}

std::string WrongAnimal::getType() const{
    return (this->type);
}

void    WrongAnimal::setType(std::string Type){
    this->type = Type;
}

void WrongAnimal::makeSound() const{
    std::cout << "Kikerikiiiih, Moooooh, Töröööööö, what animal am I?" << std::endl;
}