#include "Fixed.hpp"

int Fixed::getRawBits(void){
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point_value);
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point_value = raw;
}

Fixed::Fixed (){
    fixed_point_value = 0;
    std::cout << "Default constructor called!" << std::endl;
};

Fixed::Fixed (const Fixed &b){
    std::cout << "Copy constructor called" << std::endl;
    *this = b;
};
Fixed& Fixed::operator=(const Fixed& original){
    std::cout << "Copy assignmet operator called" << std::endl;
    fixed_point_value = original.fixed_point_value;
    return (*this);
}
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
};