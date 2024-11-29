#include "PmergeMe.hpp"

Pmerge::Pmerge() {
  
}

void Pmerge::fillVector(char *argv) {
    vec.push_back(atoi(argv));
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
    if(pairs.size() % 2 != 0) {
        impVec.insert(impVec.end(), pairs.back().begin(), pairs.back().end());
        pairs.pop_back();
    }
    for(unsigned long i = 0; i < pairs.size(); i+=2) {
        if(pairs[i][0] > pairs[i + 1][0]) {
            pairs[i].insert(pairs[i].end(), pairs[i + 1].begin(), pairs[i + 1].end());
            pairs[i + 1].clear();
            if(pairs[i + 1].empty()) {
                pairs.erase(pairs.begin() + i + 1);
                i--;
            }
        }
        else if(pairs[i + 1][0] > pairs[i][0]) {
            pairs[i + 1].insert(pairs[i + 1].end(), pairs[i].begin(), pairs[i].end());
            pairs[i].clear();
            if(pairs[i].empty()) {
                pairs.erase(pairs.begin() + i);
                i--;
            }
        }
    }
    if(impVec.size() != 0) {
        pairs[pairs.size() - 1].insert(pairs[pairs.size() - 1].end(), impVec.begin(), impVec.end());
        impVec.clear();
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