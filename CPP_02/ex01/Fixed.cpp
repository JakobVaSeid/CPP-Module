#include "Fixed.hpp"

int Fixed::getRawBits(void){
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point_value);
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point_value = raw;
}

float Fixed::toFloat(void) const{
    return ((float)fixed_point_value / (1 << fractional_bits));
}

int Fixed::toInt(void) const{
    return (fixed_point_value >> fractional_bits);
}

std::ostream& operator<<(std::ostream& COUT, const Fixed& fixed){
    COUT << fixed.toFloat();
    return (COUT);
}

Fixed::Fixed (){
    fixed_point_value = 0;
    std::cout << "Default constructor called!" << std::endl;
};

Fixed::Fixed (const Fixed &b){
    std::cout << "Copy constructor called" << std::endl;
    *this = b;
};

Fixed::Fixed (const int Integer){
    std::cout << "Int constructor called" << std::endl;
    fixed_point_value = Integer << fractional_bits;
};

Fixed::Fixed (const float Float){
    std::cout << "Float constructor called" << std::endl;
    fixed_point_value = roundf(Float * (1 << fractional_bits));
};

Fixed& Fixed::operator=(const Fixed& original){
    std::cout << "Copy assignmet operator called" << std::endl;
    fixed_point_value = original.fixed_point_value;
    return (*this);
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
};
