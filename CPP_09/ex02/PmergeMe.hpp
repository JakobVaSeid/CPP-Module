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

    public:
        Pmerge ();
        void run();
        void fillVector(char *argv);
        void createNewVec();
        void recPairs();
};