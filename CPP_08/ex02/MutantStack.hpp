#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>{
    public:
        MutantStack() : std::stack<T>() {};
        MutantStack(const MutantStack &other) : std::stack<T>(other) {};
        MutantStack &operator=(const MutantStack &other) {
            if (this != &other)
                std::stack<T>::operator=(other);
            return *this;
        };
        ~MutantStack() {};

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin() {
            return std::stack<T>::c.begin();
        };

        iterator end() {
            return std::stack<T>::c.end();
        };
};