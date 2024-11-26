#include "PmergeMe.hpp"

//print the vector
void printIntVector(std::vector<int> &vec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " " << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;
}

void printVecVector(std::vector<std::vector <int> > &vec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        printIntVector(vec[i]);
    }
    std::cout << "______________________________________________" << std::endl;
}

//swap pairs in vector pair
void swap_pair(std::pair<int, int> &vec) {
    if(vec.first > vec.second)
        return;
    int temp = vec.first;
    vec.first = vec.second;
    vec.second = temp;
}

//iterate over the vector and swap the pairs
void swap_pairs(std::vector<std::pair<int, int> > &vec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        swap_pair(vec[i]);
    }
}

int biggerNum (int num1, int num2) {
        if(num1 == num2)
            return (-1);
        if(num1 > num2)
            return num1;
        return num2;
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

void Pmerge::createNewVec() {
    if(vec.size() % 2 != 0) {
        impInt = vec.back();
        vec.pop_back();
    }
    std::vector<int> newVec;
    for(unsigned long i = 0; i < vec.size(); i+=2) {
        if(vec[i] > vec[i + 1]) {
            newVec.push_back(vec[i]);
            newVec.push_back(vec[i + 1]);
        }
        else {
            newVec.push_back(vec[i + 1]);
            newVec.push_back(vec[i]);
        }
        pairs.push_back(newVec);
        newVec.clear();
    }
}

void Pmerge::recPairs() {
    if(pairs.size() == 1) {
        return;
    }
    for(unsigned long i = 0; i < pairs.size(); i+=2) {
        if(pairs[i][0] > pairs[i + 1][0]) {
            pairs[i].insert(pairs[i].end(), pairs[i + 1].begin(), pairs[i + 1].end());
            pairs[i + 1].clear();
            if(pairs[i + 1].empty()) {
            pairs.erase(pairs.begin() + i + 1);
        }
        }
        else if(pairs[i + 1][0] > pairs[i][0]) {
            pairs[i + 1].insert(pairs[i + 1].end(), pairs[i].begin(), pairs[i].end());
            pairs[i].clear();
            if(pairs[i].empty()) {
            pairs.erase(pairs.begin() + i);
        }
        }
    }
    //erase empty vectors
    /* std::cout << "Size2: " << pairs.size() << std::endl;
    for(unsigned long i = 0; i < pairs.size(); i++) {
        if(pairs[i].empty()) {
            pairs.erase(pairs.begin() + i);
        }
    } */
    //printVecVector(newCon);
    recPairs();
} 

//recursion für pairs

void Pmerge::run() {
    createNewVec();
    //printVecVector(pairs);
    std::cout << "********************************" << std::endl;
    if(pairs.size() % 2 != 0) {
        impVec = pairs.back();
        pairs.pop_back();
    }
    recPairs();
    if(impVec.size() != 0) {
        pairs[0].insert(pairs[0].end(), impVec.begin(), impVec.end());
        impVec.clear();
    }
    printVecVector(pairs);
}

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
    printIntVector(prog.vec);
}