#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

struct Data {
        std::string string;
        size_t _nbr;
};

class Serializer {
    public:
    Serializer ();
    Serializer (Serializer const& src);
    Serializer &operator=(Serializer const& src);
    ~Serializer ();

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};