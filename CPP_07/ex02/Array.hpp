#pragma once

#include <iostream>
#include <cstdlib>
#include <exception>

template <typename T>
class Array {
    private:
        T *             _array;
        unsigend int    _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &b);
        Array &operator=(const Array &b);
        ~Array();
       
};

#include "Array.tpp"