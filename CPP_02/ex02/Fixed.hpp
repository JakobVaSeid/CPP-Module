#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

class Fixed {
    private:
        int fixed_point_value;
        static const int fractional_bits = 8;
    public:
        Fixed ();
        Fixed (const Fixed &b);
        Fixed (const int Integer);
        Fixed (const float Float);
        Fixed& operator=(const Fixed& original);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt(void) const;
        float toFloat(void) const;
        bool operator==(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator+(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        Fixed& operator--();
        Fixed& operator++();
        Fixed operator--(int);
        Fixed operator++(int);
        static Fixed& min(Fixed& f1, Fixed& f2);
        static Fixed& max(Fixed& f1, Fixed& f2);
        static const Fixed& min(const Fixed& f1, const Fixed& f2);
        static const Fixed& max(const Fixed& f1, const Fixed& f2);
};

std::ostream& operator<<(std::ostream& COUT, const Fixed& fixed);

#endif