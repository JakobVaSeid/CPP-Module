#include "easyfind.hpp"

int main () {
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);
    try {
        easyfind(vec, 5);
        easyfind(vec, 9);
        easyfind(vec, 10);
    } catch (std::exception &e) {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}