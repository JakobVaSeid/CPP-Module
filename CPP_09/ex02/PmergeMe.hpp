#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <deque>
#include <climits>
#include <ctime>

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
        ////////////////////////DEQUE////////////////////////
        std::deque<int> deq;
        std::deque <std::deque<int> > deqPairs;
        std::deque <int> impDeque;
        std::deque<unsigned long> sizeDeque;
        std::deque <int>  firstDeque;
        std::deque <int> secondDeque;
        std::deque <std::deque <int> > firstPairDeque;
        std::deque <std::deque <int> > secondPairDeque;
        std::deque <std::deque <int> > tmpDeque;
        std::deque <int> jaTaDeque;
        std::deque <unsigned long> indexHistoryDeque;
        std::deque <unsigned long> cutLenDeque;

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
        ////////////////////////DEQUE////////////////////////
        void fillDeque(char *argv);
        void createNewDeque();
        void getDequePairSize();
        void recDeqPairs();
        void divideInHalf(std::deque <int> &deq);
        void secondSort(std::deque<std::deque<int> > &tmp, unsigned long i);
        void create_jacobsthal_deq(unsigned long size);
        void recDeqSort();
        void triple_sort_deq();
        void runDeq();


};  