#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <utility>

class Pmerge {
    public:
        std::vector<int> vec;
        std::vector <std::vector<int> > pairs;
        std::vector<int> impVec;
        std::vector<unsigned long> sizeVec;
        int impInt;
        std::vector<int> first_half;
        std::vector<int> second_half;
        std::vector <std::vector <int> > firstPair;
        std::vector <std::vector <int> > secondPair;
        std::vector <std::vector <int> > tmp;
        std::vector <int> jaTaVec;
        std::vector <unsigned long> indexHistory;
        std::vector <unsigned long> cutLen;

    public:
        Pmerge ();
        ~Pmerge ();
        void run();
        void fillVector(char *argv);
        void createNewVec();
        void recPairs();
        void recSort();
        void getPairSize();
        void triple_sort();
        void divideInHalf(std::vector <int> &vec);
        void secondSort(std::vector<std::vector<int> > &tmp, unsigned long i);
        void create_jacobsthal_vec(unsigned long size);
};  