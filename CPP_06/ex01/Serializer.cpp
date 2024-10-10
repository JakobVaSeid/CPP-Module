#include "Serializer.hpp"

Serializer::Serializer() {

};

Serializer::Serializer(Serializer const& src) {
    *this = src;
};

Serializer &Serializer::operator=(Serializer const& src) {
    if (this != &src) {
        *this = src;
    }
    return *this;
};

Serializer::~Serializer() {

};


uintptr_t Serializer::serialize(Data* ptr) {
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}

Data* Serializer::deserialize(uintptr_t raw) {
    Data* ptr = reinterpret_cast<Data*>(raw);
    return ptr;
}

