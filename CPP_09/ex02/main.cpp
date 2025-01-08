#include "PmergeMe.hpp"

//10er Pairs
//Edge case test: ./PmergeMe 1 2 89 12 23 415 213 78 45 12 36 100 78 123 128 89 612 417 18 14
int main (int argc, char **argv) {
    Pmerge prog;

    if(argc < 2) {
        std::cerr << "Not enought arguments!" << std::endl;
    } else {
        for(int i = 1; i < argc; i++) {
            prog.fillVector(argv[i]);
        }
        prog.run();
    }
}