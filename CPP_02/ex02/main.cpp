#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}

/* 
int main() {
    // Test constructors
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;

    // Test assignment operator
    a = Fixed(1234.4321f);
    std::cout << "a after assignment: " << a << std::endl;

    // Test comparison operators
    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "b >= d: " << (b >= d) << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b <= d: " << (b <= d) << std::endl;
    std::cout << "b == d: " << (b == d) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;

    // Test arithmetic operators
    Fixed e = b + c;
    Fixed f = c - b;
    Fixed g = b * c;
    Fixed h = c / b;

    std::cout << "b + c: " << e << std::endl;
    std::cout << "c - b: " << f << std::endl;
    std::cout << "b * c: " << g << std::endl;
    std::cout << "c / b: " << h << std::endl;

    // Test increment and decrement operators
    Fixed i;
    std::cout << "i: " << i << std::endl;
    std::cout << "++i: " << ++i << std::endl;
    std::cout << "i++: " << i++ << std::endl;
    std::cout << "i after i++: " << i << std::endl;
    std::cout << "--i: " << --i << std::endl;
    std::cout << "i--: " << i-- << std::endl;
    std::cout << "i after i--: " << i << std::endl;

    // Test min and max functions
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
    std::cout << "min(b, d): " << Fixed::min(b, d) << std::endl;
    std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;
    std::cout << "max(b, d): " << Fixed::max(b, d) << std::endl;

    return 0;
}
 */