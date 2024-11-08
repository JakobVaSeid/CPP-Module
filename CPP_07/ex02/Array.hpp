#pragma once

#include <iostream>
#include <cstdlib>
#include <exception>

template <typename T>
class Array {
    private:
        T *             _array;
        unsigned int    _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &b);
        Array &operator=(const Array &b);
        T &operator[](unsigned int i);
        const T &operator[](unsigned int i) const;
        ~Array();
       
        unsigned int size() const;

        class OutOfLimitsException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

#include "Array.tpp"