#include "Fixed.hpp"

int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point_value);
}

void Fixed::setRawBits(int const raw){
    //std::cout << "setRawBits member function called" << std::endl;
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
    //std::cout << "Default constructor called!" << std::endl;
};

Fixed::Fixed (const Fixed &b){
    //std::cout << "Copy constructor called" << std::endl;
    *this = b;
};

Fixed::Fixed (const int Integer){
    //std::cout << "Int constructor called" << std::endl;
    fixed_point_value = Integer << fractional_bits;
};

Fixed::Fixed (const float Float){
    //std::cout << "Float constructor called" << std::endl;
    fixed_point_value = roundf(Float * (1 << fractional_bits));
};

Fixed& Fixed::operator=(const Fixed& original){
    //std::cout << "Copy assignmet operator called" << std::endl;
    fixed_point_value = original.fixed_point_value;
    return (*this);
}
Fixed::~Fixed(){
    //std::cout << "Destructor called" << std::endl;
};

//comparison operator
bool Fixed::operator==(const Fixed& other) const{
    if(this->getRawBits() == other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed& other) const{
    if(this->getRawBits() >= other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& other) const{
    if(this->getRawBits() <= other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed& other) const{
    if(this->getRawBits() != other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>(const Fixed& other) const{
    if(this->getRawBits() > other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed& other) const{
    if(this->getRawBits() < other.getRawBits())
        return (true);
    return (false);
}

//arithmetic operators
Fixed Fixed::operator-(const Fixed& other) const{
    Fixed result;
    result = this->toFloat() - other.toFloat();
    return (result);
}

Fixed Fixed::operator+(const Fixed& other) const{
    Fixed result;
    result = this->toFloat() + other.toFloat();
    return (result);
}

Fixed Fixed::operator*(const Fixed& other) const{
    Fixed result;
    result = this->toFloat() * other.toFloat();
    return (result);
}

Fixed Fixed::operator/(const Fixed& other) const{
    Fixed result;
    result = this->toFloat() / other.toFloat();
    return (result);
}

Fixed& Fixed::operator++(){
    this->fixed_point_value++;
    return (*this);
}

Fixed& Fixed::operator--(){ //--int
    this->fixed_point_value--;
    return (*this);
}

Fixed Fixed::operator++(int){ //int++
    Fixed tmp = *this;
    this->fixed_point_value++;
    return (tmp);
}

Fixed Fixed::operator--(int){
    Fixed tmp = *this;
    this->fixed_point_value--;
    return (tmp);
}

// Overload member function
Fixed& Fixed::min(Fixed& f1, Fixed& f2){
    if(f1.fixed_point_value < f2.fixed_point_value)
        return (f1);
    else
        return (f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2){
    if(f1.fixed_point_value > f2.fixed_point_value)
        return (f1);
    else
        return (f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2){
    if(f1.fixed_point_value < f2.fixed_point_value)
        return (f1);
    else
        return (f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2){
    if(f1.fixed_point_value > f2.fixed_point_value)
        return (f1);
    else
        return (f2);
}