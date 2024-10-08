#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cstdlib>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4


class ScalarConverter {
    private:

    public:
        ScalarConverter();
        ScalarConverter(ScalarConverter &b);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        static void convert(std::string value);
};