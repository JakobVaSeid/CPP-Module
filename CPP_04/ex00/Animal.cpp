#include "Animal.hpp"

Animal::Animal(){
    this->type = "Animal";
    std::cout << "Animal-constructor called!" << std::endl;
}

Animal::Animal(const Animal &b){
    std::cout << "Copy-constructor Animal!" << std::endl;
    *this = b;
}

Animal::~Animal(){
    std::cout << "Animal-destructor called!" << std::endl;
}

Animal& Animal::operator=(const Animal& other){
    if(this != &other){
    this->type = other.type;
    }
    return (*this);
}

std::string Animal::getType() const{
    return (this->type);
}

void    Animal::setType(std::string Type){
    this->type = Type;
}

void Animal::makeSound() const{
    std::cout << "Kikerikiiiih, Moooooh, Töröööööö, what animal am I?" << std::endl;
}