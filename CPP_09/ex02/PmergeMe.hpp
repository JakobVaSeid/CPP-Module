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
        int impInt;
        std::vector<int> first_half;
        std::vector<int> second_half;
        std::vector <std::vector <int> > firstPair;
        std::vector <std::vector <int> > secondPair;
        std::vector <std::vector <int> > tmp;

    public:
        Pmerge ();
        void run();
        void fillVector(char *argv);
        void createNewVec();
        void recPairs();
        void recSort();
        void divideInHalf(std::vector <int> &vec);
        void firstSort(std::vector<std::vector<int> > &tmp);
        void secondSort(std::vector<std::vector<int> > &tmp, unsigned long i);
};  