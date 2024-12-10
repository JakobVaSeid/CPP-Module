#include "PmergeMe.hpp"

Pmerge::Pmerge() {
  
}

void Pmerge::fillVector(char *argv) {
    vec.push_back(atoi(argv));
}

//print the vector
void printIntVector(std::vector<int> &vec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

void printLongVector(std::vector<unsigned long> &vec) {
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

void Pmerge::createNewVec() {
    printIntVector(vec);
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

void Pmerge::getPairSize () {
    int sizeFirst = 0;
    int sizeLast = 0;
    sizeFirst = pairs[0].size();
    sizeLast = pairs[pairs.size() - 1].size();
    sizeVec.push_back(sizeFirst);
    sizeVec.push_back(sizeLast);
}

void Pmerge::recPairs() {
    printVecVector(pairs);
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
    getPairSize();
    
    std::cout << "SIZEVEC: ";
    printLongVector(sizeVec);
    recPairs();
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

//is power of 2
bool isPowerOfTwo (unsigned long x) {
    return x && (!(x & (x - 1)));
}

void Pmerge::recSort() {
    //std::vector<int> tmpVec;
    sizeVec.pop_back();
    sizeVec.pop_back();
    if(pairs.size() == 1) {
        if(sizeVec.size() > 1 || sizeVec[sizeVec.size() - 1] != 0) {
            for (unsigned long i = 0; i < sizeVec[sizeVec.size() - 1]; i++) {
                impVec.insert(impVec.begin(), pairs[pairs.size() - 1].back());
                //impVec.push_front(pairs[pairs.size() - 1].back());
                pairs[pairs.size() - 1].pop_back();
            }
        }
    }
    /* if(pairs.size() == 1) {
        std::cout << "Here" << std::endl;
        firstSort(firstPair);
        pairs.clear();
        pairs.push_back(firstPair[0]);
        pairs.push_back(firstPair[1]);
        firstPair.clear();
        printVecVector(pairs);
    } */
    pairs.insert(pairs.begin(), impVec);
    impVec.clear();
    printVecVector(pairs);
    if(pairs.size() > 1)
    {
        for(unsigned long i = 0; i < pairs.size(); i++) {
            std::cout << "Pairs size: " << pairs[i].size() << std::endl;
            std::cout << "SizeVec[-2]: " << sizeVec[sizeVec.size() - 2] << std::endl;
            std::cout << "SizeVec[-1]: " << sizeVec[sizeVec.size() - 1] << std::endl;
            if(pairs[i].size() == sizeVec[sizeVec.size() - 2]) {
                std::cout << "Here" << std::endl;
                /* if(i == 0) {
                    firstSort(firstPair);
                    pairs.insert(pairs.begin(), firstPair[0]);
                    pairs.insert(pairs.begin() + 1, firstPair[1]);
                    pairs.erase(pairs.begin() + 2);
                    firstPair.clear();
                    i++;
                }
                else { */
                    secondSort(secondPair, i);
                    std::vector<std::vector<int> >::iterator it = std::lower_bound(pairs.begin(), pairs.end(), secondPair[0]);
                    pairs.insert(it, secondPair[0]);
                    pairs.insert(pairs.begin() + i + 1, secondPair[1]);
                    i++;
                    pairs.erase(pairs.begin() + i + 1);
                    secondPair.clear();
                //}
            } else if (pairs[i].size() == sizeVec[sizeVec.size() - 1]) {
                std::cout << "Here2" << std::endl;
                std::cout << "SizeVec[-3]: " << sizeVec[sizeVec.size() - 3] << std::endl;
                if(sizeVec.size() > 1 || sizeVec[sizeVec.size() - 3] != 0) {
                    for (unsigned long j = 0; j < sizeVec[sizeVec.size() - 3]; j++) {
                        impVec.insert(impVec.begin(), pairs[i].back());
                        //impVec.push_front(pairs[pairs.size() - 1].back());
                        pairs[i].pop_back();
                    }
                    printIntVector(impVec);
                    pairs.insert(pairs.begin(), impVec);
                    impVec.clear();
                }
                sizeVec.pop_back();
            }
        }
        printVecVector(pairs);
        /* std::cout << "IMPVEC: " << std::endl;
        printIntVector(impVec);
        std::cout << "......................................" << std::endl; */
        for(unsigned long i = 0; i < impVec.size(); i++) {
            pairs[pairs.size() - 1].push_back(impVec[i]);
            impVec.pop_back();
            impVec.erase(impVec.begin() + i);
        }
    }
    
    unsigned long counter = 0;
    for(unsigned long i = 0; i < pairs.size(); i++) {
        if(pairs[i].size() == 1)
            counter++;
        if(counter + 2 == pairs.size())
            return;
    }
    //recSort();
}


void Pmerge::run() {
    std::cout << "****************1.Step****************" << std::endl;
    createNewVec();
    printVecVector(pairs);
    recPairs();
    //printVecVector(pairs);
    std::cout << "****************2.Step****************" << std::endl;
    //Diesen block in eine Funktion auslagern
    /* if((pairs[0].size() / 2) % 2 != 0) {
        std::cout << "Here" << std::endl;
        impVec.push_back(pairs[0].back());
        pairs.back().pop_back();
        impVec.push_back(pairs[0].back());
        pairs.back().pop_back();
        printIntVector(impVec);
    } */
    /* std::cout << "Pairs size: " << pairs[0].size() << std::endl;
    std::cout << "SizeVec[END]: " << sizeVec[sizeVec.size() - 1] << std::endl; */
    //in recSort auslagern
    
    std::cout << "****************3.Step****************" << std::endl;
    recSort();
    recSort();
    // recSort();
    // recSort();
    // recSort();
}