#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <cerrno>
#include <limits>


#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4


class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter &b);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

    public:
        static void convert(std::string value);
};