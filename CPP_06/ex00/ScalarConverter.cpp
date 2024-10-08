#include "ScalaConverter.hpp"

////////////////
ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(ScalarConverter &b) {
    *this = b;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if(this != &other){
        *this = other;
    }
    return (*this);
}
ScalarConverter::~ScalarConverter() {

}

/* int check_type(std::string value) {
    std::string::const_iterator it = value.begin();
    bool hasDecimalPoint = false;
    bool hasExponent = false;

    if(*it == '+' || *it == '-')
        it++;
    while (it != value.end() && (std::isdigit(*it) || *it == '.' || *it == 'e' || *it == 'E' || *it == 'f')) {
        if (*it == '.') {
            if (hasDecimalPoint) 
                return CHAR;
            hasDecimalPoint = true;
        } else if (*it == 'e' || *it == 'E') {
            if (hasExponent) 
                return CHAR;
            hasExponent = true;
        } else if (*it == 'f' && it + 1 == value.end()) {
            return FLOAT;
        }
        it++;
    }
    if (it == value.end()) {
        if (hasDecimalPoint || hasExponent) 
            return DOUBLE;
        return INT;
    }
    return CHAR;
} */


//check if value is C++ literal
int check_pseudo_literals (std::string value) {
    if(value == "-inff" || value == "+inff" || value == "nanf")
        return (1);
    if(value == "-inf" || value == "+inf" || value == "nan")
        return (2);
    return (0);
}

bool char_check(std::string value) {
    if(value.length() != 1)
        return (false);
    if (!isprint(value[0])) {
        std::cout << "Not printable char!" << std::endl;
        return (false);
    }
    if(isdigit(value[0]) || !std::isalpha(value[0]))
        return (false);
    return (true);
}

//check if value has attributes of a double
bool double_check(std::string value) {
    std::string::const_iterator it = value.begin();
    bool hasDecimalPoint = false;
    bool hasExponent = false;

    if(*it == '+' || *it == '-')
        it++;
    while (it != value.end() && (std::isdigit(*it) || *it == '.' || *it == 'f')) {
        if (*it == '.') {
            if (hasDecimalPoint) 
                return (false);
            hasDecimalPoint = true;
        } else if (*it == 'f' && it + 1 == value.end()) {
            return (false);
        }
        it++;
    }
    if (it == value.end()) {
        if (hasDecimalPoint || hasExponent) 
            return (true);
        return (false);
    }
    return (false);
}

//check if value has attributes of a float
bool float_check(std::string value) {
    std::string::const_iterator it = value.begin();
    bool hasDecimalPoint = false;

    if(*it == '+' || *it == '-')
        it++;
    while (it != value.end() && (std::isdigit(*it) || *it == '.' || *it == 'f')) {
        if (*it == '.') {
            if (hasDecimalPoint) 
                return (false);
            hasDecimalPoint = true;
        } else if (*it == 'f' && it + 1 == value.end()) {
            return (true);
        }
        it++;
    }
    if (it == value.end()) {
        if (hasDecimalPoint) 
            return (false);
        return (false);
    }
    return (false);
}

//which type of value is it?
int check_type(std::string value) {
    std::stringstream ss(value);
    char c;
    int i;
    double d;
    float f;

    if(check_pseudo_literals(value) == 1)
        return (FLOAT);
    if(check_pseudo_literals(value) == 2)
        return (DOUBLE);

    ss >> c;
    if (ss.fail() || !char_check(value)) {
        ss.clear();
        ss.str(value);
        ss >> i;
        if (ss.fail() || double_check(value) || float_check(value)) {
            ss.clear();
            ss.str(value);
            ss >> d;
            if (ss.fail() || float_check(value)) {
                ss.clear();
                ss.str(value);
                ss >> f;
                if (ss.fail()) {
                    return (0);
                }
                return (FLOAT);
            }
            return (DOUBLE);
        }
        return (INT);
    }
    return (CHAR);
}

//print if is pseudo literals
void print_pseudo_literals(std::string value) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if(check_pseudo_literals(value) == 1) {
        std::cout << "float: " << value << std::endl;
        std::cout << "double: " << value.substr(0, (value.length() - 1)) << std::endl;
    }
    if(check_pseudo_literals(value) == 2) {
        std::cout << "float: " << value << "f" << std::endl;
        std::cout << "double: " << value << std::endl;
    }
}

//convert form char to other types
void convert_char(std::string value) {
    std::stringstream ss(value);
    char c;
    int i;
    double d;
    float f;

    ss >> c;
    i = static_cast<int>(c);
    d = static_cast<double>(c);
    f = static_cast<float>(c);
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

//convert form int to other types
void convert_int(std::string value) {
    std::stringstream ss(value);
    char c;
    int i;
    double d;
    float f;

    ss >> i;
    c = static_cast<char>(i);
    d = static_cast<double>(i);
    f = static_cast<float>(i);
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

//convert form float to other types
void convert_float(std::string value) {
    std::stringstream ss(value);
    std::cout << value << std::endl;
    char c;
    int i;
    double d;
    float f;

    ss >> f;
    c = static_cast<char>(f);
    i = static_cast<int>(f);
    d = static_cast<double>(f);
    if(check_pseudo_literals(value))
        print_pseudo_literals(value);
    else {
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}

//convert form double to other types
void convert_double(std::string value) {
    std::stringstream ss(value);
    char c;
    int i;
    double d;
    float f;

    ss >> d;
    c = static_cast<char>(d);
    i = static_cast<int>(d);
    f = static_cast<float>(d);
    if(check_pseudo_literals(value))
        print_pseudo_literals(value);
    else {
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}

void ScalarConverter::convert (std::string value) {    
    std::cout << "Type: " << check_type(value) << std::endl;    
    
    if(check_type(value) == CHAR) {
        convert_char(value);
    } else if (check_type(value) == INT) {
        convert_int(value);
    } else if (check_type(value) == FLOAT) {
        convert_float(value);
    } else if (check_type(value) == DOUBLE) {
        convert_double(value);
    } else {
        std::cout << "Error" << std::endl;
    }
}
/* bool convert_to_char(std::string value) {
    if(check_pseudo_literals(value))
        std::cout << "char: impossible" << std::endl;
    if(value.length() != 1)
        return (false);
    std::stringstream ss(value);
    char c;
    
    ss >> c;
    if (ss.fail()) {
        return (false);
    }
    if (!isprint(c)) {
        std::cout << "Not printable char!" << std::endl;
        return (false);
    }
    std::cout << "char: " << c << std::endl;
    return (true);
}

bool convert_to_int(std::string value) {
    if(check_pseudo_literals(value))
        std::cout << "int: impossible" << std::endl;
    std::stringstream ss(value);
    int i;
    
    ss >> i;
    if (ss.fail()) {
        return (false);
    }
    std::cout << "int: " << i << std::endl;
    return (true);
}

bool convert_to_float(std::string value) {
    if(check_pseudo_literals(value) == 1) {
        std::cout << "float: " << value << std::endl;
        return (true);
    } else if (check_pseudo_literals(value) == 2) {
        std::cout << "float: " << value << "f" << std::endl;
        return (true);
    }
    std::stringstream ss(value);
    float f;
    
    ss >> f;
    if (ss.fail()) {
        return (false);
    }
    std::cout << "float: " << f << std::endl;
    return (true);
}

bool convert_to_double(std::string value) {
    if(check_pseudo_literals(value) == 2) {
        std::cout << "double: " << value << std::endl;
        return (true);
    } else if (check_pseudo_literals(value) == 1) {
        std::cout << "double: " << value.substr(0, (value.length() - 1)) << std::endl;
        return (true);
    }
    std::stringstream ss(value);
    double d;
    
    ss >> d;
    if (ss.fail()) {
        return (false);
    }
    std::cout << "double: " << d << std::endl;
    return (true);
}
 */
