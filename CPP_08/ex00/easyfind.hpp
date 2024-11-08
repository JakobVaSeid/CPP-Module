#pragma once

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

template <typename T>
void easyfind (T &con, int i) {
    typename T::iterator it;
    it = std::find(con.begin(), con.end(), i);
    if (it == con.end())
        throw std::exception();
    std::cout << "Found: " << *it << std::endl;
}
