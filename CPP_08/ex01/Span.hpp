#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _v;
    
    public:
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int n);
        void addmoreNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();

};
