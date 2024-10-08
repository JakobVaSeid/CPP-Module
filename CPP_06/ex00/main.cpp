#include "ScalaConverter.hpp"

void convert_to_int(std::string value);

int main (int argc, char **argv) {

    if(argc != 2){
        return (std::cout << "Error" << std::endl, 0);
    } else
    {
        ScalarConverter A;

        A.convert(argv[1]);

        /* std::string valueA = "1";
        std::string valueB = "A";
        std::string valueC = "+inff";
        std::string valueD = "-42";
        std::string valueF = "A";


        A.convert(valueA);
        std::cout << "-------------------" << std::endl;
        A.convert(valueB);
        std::cout << "-------------------" << std::endl;
        A.convert(valueC);
        std::cout << "-------------------" << std::endl;
        A.convert(valueD);
        std::cout << "-------------------" << std::endl;
        A.convert(valueF); */
    }
}