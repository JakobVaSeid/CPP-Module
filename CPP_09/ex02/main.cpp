#include "PmergeMe.hpp"

//print the vector
void printIntVector(std::vector<int> &vec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

void printVecVector(std::vector<std::vector <int> > &vec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        printIntVector(vec[i]);
    }
    std::cout << "______________________________________________" << std::endl;
}

int jacobsthal(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int prev2 = 0, prev1 = 1, current = 0;
    for (int i = 2; i <= n; ++i) {
        current = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

void Pmerge::divideInHalf(std::vector <int> &vec) {
    long half = vec.size() / 2;
    for(int i = 0; i < half; i++) {
        first_half.push_back(vec[i]);
    }
    for(unsigned long i = half; i < vec.size(); i++) {
        second_half.push_back(vec[i]);
    }
}

void Pmerge::firstSort(std::vector<std::vector<int> > &tmp) {
    divideInHalf(pairs[0]);
    tmp.push_back(second_half);
    tmp.push_back(first_half);
    second_half.clear();
    first_half.clear();
}

void Pmerge::secondSort(std::vector<std::vector<int> > &tmp, unsigned long i) {
    divideInHalf(pairs[i]);
    tmp.push_back(second_half);
    tmp.push_back(first_half);
    second_half.clear();
    first_half.clear();
}

void Pmerge::recSort() {   
    std::cout << "--PAIRS-1--" << std::endl;
                printVecVector(pairs);
    //tmp = pairs;
    unsigned long size = pairs.size();
    if(size > 1)
    {
        for(unsigned long i = 0; i < pairs.size(); i++) {
            std::cout << "Big i: " << i << std::endl;
            if(i == 0) {
                firstSort(firstPair);
                std::cout << "here" << std::endl;
                pairs.insert(pairs.begin(), firstPair[0]);
                pairs.insert(pairs.begin() + 1, firstPair[1]);
                pairs.erase(pairs.begin() + 2);
                firstPair.clear();
                size += 1;
                i++;
            }
            else {
                secondSort(secondPair, i);
                //lower_bound
                /* std::vector<std::vector<int> >::iterator it = std::lower_bound(pairs.begin(), pairs.end(), secondPair[0]);
                std::cout << "It: " << *it[0] << std::endl; */
                pairs.insert(pairs.begin() + i, secondPair[0]);
                pairs.insert(pairs.begin() + i + 1, secondPair[1]);
                i++;
                pairs.erase(pairs.begin() + i + 1);
                secondPair.clear();
            }
            /* pairs.clear();
            pairs = tmp; */
        }
    }
        std::cout << "--PAIRS-2--" << std::endl;
        std::cout << "Pairs size: " << pairs.size() << std::endl;
                printVecVector(pairs);
    unsigned long counter = 0;
    for(unsigned long i = 0; i < pairs.size(); i++) {
        if(pairs[i].size() == 1)
            counter++;
        std::cout << "Counter: " << counter << std::endl;
        std::cout << "Size: " << pairs.size() << std::endl;
        if(counter + 2 == pairs.size())
            return;
    }
    recSort();
}


void Pmerge::run() {
    std::cout << "****************1.Step****************" << std::endl;
    createNewVec();
    recPairs();
    printVecVector(pairs);
    std::cout << "****************2.Step****************" << std::endl;
    //Diesen block in eine Funktion auslagern
    if(pairs.size() == 1) {
        firstSort(firstPair);
        pairs.clear();
        pairs.push_back(firstPair[0]);
        pairs.push_back(firstPair[1]);
        firstPair.clear();
    }
    std::cout << "****************3.Step****************" << std::endl;
    recSort();
    //recSort();
    //recSort();
    //recSort();
    //recSort();
}
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
    //printIntVector(prog.vec);
}