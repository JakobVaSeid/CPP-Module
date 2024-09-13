#include "Cat.hpp"

Cat::Cat(){
    this->type = "Cat";
    std::cout << "Cat-constructor called!" << std::endl;
};

Cat::Cat(const Cat &b):Animal(b){
    std::cout << "Copy-constructor Cat!" << std::endl;
    *this = b;
}

Cat::~Cat(){
    std::cout << "Cat-destructor called!" << std::endl;
}

Cat& Cat::operator=(const Cat& other){
    if(this != &other){
    this->type = other.type;
    }
    return (*this);
}

void Cat::makeSound() const{
    std::cout << "Meow Meow!" << std::endl;
}