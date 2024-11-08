#include "Array.hpp"

template <typename T>
Array<T>::Array() {
    _size = 0;
    _array = new T[0];
};

template <typename T>
Array<T>::Array(unsigned int n) {
    _size = n;
    _array = new T[n];
};

template <typename T>
Array<T>::Array(const Array &b) {
    _size = b.size();
    _array = new T[b.size()];
    for (unsigned int i = 0; i < b.size(); i++) {
        _array[i] = b[i];
    }
};

template <typename T>
Array<T> &Array<T>::operator=(const Array &b) {
    if (this != &b) {
        delete[] _array;
        _size = b.size();
        _array = new T[b.size()];
        for (unsigned int i = 0; i < b.size(); i++) {
            _array[i] = b[i];
        }
    }
    return *this;
};

template <typename T>
T &Array<T>::operator[](unsigned int i) {
    if (i >= _size) {
        throw OutOfLimitsException();
    }
    return _array[i];
};

template <typename T>
const T &Array<T>::operator[](unsigned int i) const{
    if (i >= _size) {
        throw OutOfLimitsException();
    }
    return _array[i];
};

template <typename T>
Array<T>::~Array() {
    delete[] _array;
};

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
};

template <typename T>
const char* Array<T>::OutOfLimitsException::what() const throw() {
    return "Index out of limits";
}