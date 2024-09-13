#include "Dog.hpp"

Dog::Dog(){
    this->type = "Dog";
    std::cout << "Dog-constructor called!" << std::endl;
};

Dog::Dog(const Dog &b):Animal(b){
    std::cout << "Copy-constructor Dog!" << std::endl;
    *this = b;
}

Dog::~Dog(){
    std::cout << "Dog-destructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& other){
    if(this != &other){
    this->type = other.type;
    }
    return (*this);
}

void Dog::makeSound() const{
    std::cout << "Woof Woof!" << std::endl;
}