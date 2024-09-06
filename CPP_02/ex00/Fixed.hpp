#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int fixed_point_value;
        static const int fractional_bits = 8;
    public:
        Fixed ();
        Fixed (const Fixed &b);
        Fixed& operator=(const Fixed& original);
        ~Fixed();
        int getRawBits(void);
        void setRawBits(int const raw);
};

#endif