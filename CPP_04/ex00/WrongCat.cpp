#include "WrongCat.hpp"

WrongCat::WrongCat(){
    this->type = "WrongCat";
    std::cout << "WrongCat-constructor called!" << std::endl;
};

WrongCat::WrongCat(const WrongCat &b):WrongAnimal(b){
    std::cout << "Copy-constructor WrongCat!" << std::endl;
    *this = b;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat-destructor called!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
    if(this != &other){
    this->type = other.type;
    }
    return (*this);
}

void WrongCat::makeSound() const{
    std::cout << "Öööh I guess I am making mooooh?" << std::endl;
}