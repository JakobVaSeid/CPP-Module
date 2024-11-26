#include "PmergeMe.hpp"

Pmerge::Pmerge() {
  
}

void Pmerge::fillVector(char *argv) {
    vec.push_back(atoi(argv));
}