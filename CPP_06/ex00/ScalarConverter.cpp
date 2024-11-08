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

bool check_overflow(const std::string& value) {
    std::stringstream ss(value);
    long temp;
    ss >> temp;
    if (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min()) {
        throw (std::overflow_error("Overflow detected"));
    }
    return false;
}

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

bool int_check(std::string value) {
    std::string::const_iterator it = value.begin();
    if(*it == '+' || *it == '-')
        it++;
    while (it != value.end() && std::isdigit(*it)) {
        it++;
    }
    if (it == value.end()) {
        return (true);
    }
    return (false);
}

bool check_dot(std::string value) {
    int dot = 0;
    for (unsigned long i = 0; i < value.length(); i++) {
        if (value[i] == '.')
            dot++;
    }
    if (dot > 1)
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

//check if value is valid
bool check_input(std::string value) {
    if(value.length() == 0)
        return (false);
    if(!check_dot(value))
        return (false);
    if(!char_check(value) && !int_check(value) && !double_check(value) && !float_check(value) && !check_pseudo_literals(value))
        return (false);
    return (true);
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

int printable (int i) {
    if((i < 32 && i >= 0) || (i > 126 && i <= 255))
        return (2);
    if(i >= 32 && i <= 126)
        return (1);
    return (0);
}

void print_char(int i) {
    if(printable(i) == 0)
        std::cout << "char: impossible" << std::endl;
    else if(printable(i) == 2)
        std::cout << "char: non displayable" << std::endl;
}

//convert form char to other types
void convert_char(std::string value) {
    std::cout << "---character---" << std::endl;
    std::stringstream ss(value);
    char c;
    int i;
    double d;
    float f;

    ss >> c;
    i = static_cast<int>(c);
    d = static_cast<double>(c);
    f = static_cast<float>(c);
    std::cout << "char: " << "'" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
    std::cout << "double: " << d << ".0" << std::endl;
}

//convert form int to other types
void convert_int(std::string value) {
    if(check_overflow(value))
        return ;
    std::cout << "---integer---" << std::endl;
    std::stringstream ss(value);
    char c;
    int i;
    double d;
    float f;

    ss >> i;
    c = static_cast<char>(i);
    d = static_cast<double>(i);
    f = static_cast<float>(i);
    if(printable(i) == 1)
        std::cout << "char: " << "'" << c << "'" << std::endl;
    else
        print_char(i);
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

//Has . in it
bool has_dot(std::string value) {
    for (unsigned long i = 0; i < value.length(); i++) {
        if (value[i] == '.')
            return (true);
    }
    return (false);
}

//convert form float to other types
void convert_float(std::string value) {
    if(check_overflow(value))
        return ;
    std::cout << "---float---" << std::endl;
    std::stringstream ss(value);
    char c;
    int i;
    double d;
    float f;

    ss >> f;
    c = static_cast<char>(f);
    i = static_cast<int>(f);
    d = static_cast<double>(f);
    std::stringstream strStream;
    strStream << f;
    std::string str = strStream.str();
    if(check_pseudo_literals(value))
        print_pseudo_literals(value);
    else if(has_dot(str)) {
        if(printable(i) == 1)
            std::cout << "char: " << "'" << c << "'" << std::endl;
        else
            print_char(i);
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(15);
        std::cout << "double: " << d << std::endl;
        std::cout.unsetf(std::ios::fixed);
    }
    else {
        if(printable(i) == 1)
            std::cout << "char: " << "'" << c << "'" << std::endl;
        else
            print_char(i);
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" << std::endl;
    }
}

//convert form double to other types
void convert_double(std::string value) {
    if(check_overflow(value))
        return ;
    std::cout << "---double---" << std::endl;
    std::stringstream ss(value);
    char c;
    int i;
    double d;
    float f;

    ss >> d;
    c = static_cast<char>(d);
    i = static_cast<int>(d);
    f = static_cast<float>(d);
    std::stringstream strStream;
    strStream << d;
    std::string str = strStream.str();
    if(check_pseudo_literals(value))
        print_pseudo_literals(value);
    else if(has_dot(str)) {
        if(printable(i) == 1)
            std::cout << "char: " << c << std::endl;
        else
            print_char(i);
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(15);
        std::cout << "double: " << d << std::endl;
        std::cout.unsetf(std::ios::fixed);
    }
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" << std::endl;
    }
}

void ScalarConverter::convert (std::string value) {
    if(check_input(value) == false) {
        std::cout << "Error: \nInvalid input!" << std::endl;
        return ;
    }
    if(check_type(value) == CHAR) {
        convert_char(value);
    } else if (check_type(value) == INT) {
        convert_int(value);
    } else if (check_type(value) == FLOAT) {
        convert_float(value);
    } else if (check_type(value) == DOUBLE) {
        convert_double(value);
    } else {
        std::cout << "Error: \nNo matching type!" << std::endl;
    }
}

