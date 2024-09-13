#include "Dog.hpp"

Dog::Dog(){
    this->type = "Dog";
    this->_brain = new Brain();
    //std::cout << "Dog-constructor called!" << std::endl;
};

Dog::Dog(const Dog &b):Animal(b){
    std::cout << "Copy-constructor Dog!" << std::endl;
    this->_brain = new Brain(*b._brain);
}

Dog::~Dog(){
    //std::cout << "Dog-destructor called!" << std::endl;
    delete this->_brain;
}

Dog& Dog::operator=(const Dog& other){
    if(this != &other){
    this->type = other.type;
    delete this->_brain;
    this->_brain = new Brain(*other._brain);
    }
    return (*this);
}

void Dog::makeSound() const{
    std::cout << "Woof Woof!" << std::endl;
}

void Dog::setTought(std::string idea, int i){
    this->_brain->setTought(idea, i);
}

std::string Dog::getTought(int i){
    return (this->_brain->getTought(i));
}