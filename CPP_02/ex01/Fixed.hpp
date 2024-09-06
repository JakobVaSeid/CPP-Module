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
        int getRawBits(void);
        void setRawBits(int const raw);
        int toInt(void) const;
        float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& COUT, const Fixed& fixed);

#endif