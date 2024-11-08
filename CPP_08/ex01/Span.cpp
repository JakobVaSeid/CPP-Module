#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {

};

Span::Span(const Span &other) {
    *this = other;
};

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _n = other._n;
        _v = other._v;
    }
    return *this;
};

Span::~Span() {

};

void Span::addNumber(int n) {
    if (_v.size() == _n)
        throw std::runtime_error("Error: Span is full");
    _v.push_back(n);
};

void Span::addmoreNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    int size;
    for (size = 0; begin != end; begin++)
        size++;
    if (_v.size() + size > _n)
        throw std::runtime_error("Error: Span is full");
    _v.insert(_v.end(), begin, end);
};

int Span::shortestSpan() {
    if (_v.size() < 2)
        throw std::runtime_error("Error: Span is too short");
    std::sort(_v.begin(), _v.end());
    int min = _v[1] - _v[0];
    for (unsigned int i = 2; i < _v.size(); i++) {
        if (_v[i] - _v[i - 1] < min)
            min = _v[i] - _v[i - 1];
    }
    return min;
};

int Span::longestSpan() {
    if (_v.size() < 2)
        throw std::runtime_error("Error: Span is too short");
    std::sort(_v.begin(), _v.end());
    int max = _v[_v.size() - 1] - _v[0];
    return max;
};

