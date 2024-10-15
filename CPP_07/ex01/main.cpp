#include "iter.hpp"

void print(int &i) {
    std::cout << i << std::endl;
}

void add_one(int &i) {
    i++;
}

void multiply_by_two(int &i) {
    i *= 2;
}

int main () {
    int tab[] = {0, 1, 2, 3, 4};
    ::iter(tab, 5, print);
    std::cout << "_______________________" << std::endl;
    ::iter(tab, 5, add_one);
    ::iter(tab, 5, print);
    std::cout << "_______________________" << std::endl;
    ::iter(tab, 5, multiply_by_two);
    ::iter(tab, 5, print);
    return 0;
}