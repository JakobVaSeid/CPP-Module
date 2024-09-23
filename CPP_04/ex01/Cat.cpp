#include "Cat.hpp"

Cat::Cat(){
    this->type = "Cat";
    this->_brain = new Brain("Catfood!");
    //std::cout << "Cat-constructor called!" << std::endl;
};

Cat::Cat(const Cat &b):Animal(b){
    std::cout << "Copy-constructor Cat!" << std::endl;
    this->_brain = new Brain(*b._brain);
}

Cat::~Cat(){
    //std::cout << "Cat-destructor called!" << std::endl;
    delete this->_brain;
}

Cat& Cat::operator=(const Cat& other){
    if(this != &other){
    this->type = other.type;
    delete this->_brain;
    this->_brain = new Brain(*other._brain);
    }
    return (*this);
}

void Cat::makeSound() const{
    std::cout << "Meow Meow!" << std::endl;
}

void Cat::setTought(std::string idea, int i){
    this->_brain->setTought(idea, i);
}

std::string Cat::getTought(int i){
    return (this->_brain->getTought(i));
}