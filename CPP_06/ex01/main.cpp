#include "Serializer.hpp"

int main () {
    //Success Case
    {
        Serializer s;
        Data d;
        uintptr_t raw;

        d.string = "Hello";
        d._nbr = 42;

        raw = s.serialize(&d);
        std::cout << "Serialized: " << raw << std::endl;

        Data* ptr = s.deserialize(raw);
        std::cout << "Deserialized: " << ptr->string << " " << ptr->_nbr << std::endl;
        if(ptr->string == d.string && ptr->_nbr == d._nbr) {
            std::cout << "\033[32m"<< "Success" << "\033[0m" <<std::endl;
        } else {
            std::cout << "\033[31m"<< "Failure" << "\033[0m" <<std::endl;
        }
    }

    return 0;
}