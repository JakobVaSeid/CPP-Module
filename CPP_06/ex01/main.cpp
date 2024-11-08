#include "Serializer.hpp"

int main () {
    //Success Case
    {
        //Serializer s;
        Data d;
        uintptr_t raw = 0;

        d.string = "Hello";
        d._nbr = 42;

        std::cout << "before Serialized: " << d.string << std::endl;
        std::cout << "before Serialized: " << &d.string << std::endl;

        raw = Serializer::serialize(&d);
        std::cout << "after Serialized: " << raw << std::endl;
        std::cout << "after Serialized: " << raw << std::endl;

        Data* ptr = Serializer::deserialize(raw);
        std::cout << "Deserialized: " << ptr->string << " " << ptr->_nbr << std::endl;
        std::cout << "Deserialized: " << &ptr->string << std::endl;

        if(ptr->string == d.string && ptr->_nbr == d._nbr) {
            std::cout << "\033[32m"<< "Success" << "\033[0m" <<std::endl;
        } else {
            std::cout << "\033[31m"<< "Failure" << "\033[0m" <<std::endl;
        }
    }

    return 0;
}