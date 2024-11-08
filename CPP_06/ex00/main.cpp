#include "ScalaConverter.hpp"

//ceck input bigger int max or smaller int min


int main (int argc, char **argv) {

    try {
        if(argc != 2){
            return (std::cout << "Error: need one argument" << std::endl, 0);
        } else
            ScalarConverter::convert(argv[1]);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}