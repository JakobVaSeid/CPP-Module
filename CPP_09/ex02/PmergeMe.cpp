#include "PmergeMe.hpp"

Pmerge::Pmerge() {
  impInt = -1;
}

void Pmerge::fillVector(char *argv) {
    vec.push_back(atoi(argv));
}

//print the vector
void printIntVector(std::vector<int> &vec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        std::cout << "\033[32m" << vec[i] << "\033[0m ";
    }
    std::cout << std::endl;
    std::cout << "\033[32m----------------------------------------------\033[0m" << std::endl;
}

void printLongVector(std::vector<unsigned long> &vec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        std::cout << "\033[33m" << vec[i] << "\033[0m ";
    }
    std::cout << std::endl;
    std::cout << "\033[33m----------------------------------------------\033[0m" << std::endl;
}

void printVecVector(std::vector<std::vector <int> > &vec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        printIntVector(vec[i]);
    }
    std::cout << "______________________________________________" << std::endl;
}

void printIntVectorPurple(std::vector<int> &vec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        std::cout << "\033[35m" << vec[i] << "\033[0m ";
    }
    std::cout << std::endl;
    std::cout << "\033[35m----------------------------------------------\033[0m" << std::endl;
}

void printIntVectorBlue(std::vector<int> &vec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        std::cout << "\033[34m" << vec[i] << "\033[0m ";
    }
    std::cout << std::endl;
    std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
}

void printVecVectorRed(std::vector<std::vector <int> > &vec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        for(unsigned long j = 0; j < vec[i].size(); j++) {
            std::cout << "\033[31m" << vec[i][j] << "\033[0m ";
        }
        std::cout << std::endl;
        std::cout << "\033[31m----------------------------------------------\033[0m" << std::endl;
    }
    std::cout << "______________________________________________" << std::endl;
}

void printVecVectorBlue(std::vector<std::vector <int> > &vec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        for(unsigned long j = 0; j < vec[i].size(); j++) {
            std::cout << "\033[34m" << vec[i][j] << "\033[0m ";
        }
        std::cout << std::endl;
        std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
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
// bigger vec.size() front is 0 else 1
void Pmerge::recPairs() {
    printVecVector(pairs);
    getPairSize();
    if(pairs.size() == 2 || pairs.size() == 3) {
        return;
    }
    if(pairs.size() % 2 != 0) {
        impVec.insert(impVec.end(), pairs.back().begin(), pairs.back().end());
        pairs.pop_back();
    }
    for(unsigned long i = 0; i < pairs.size(); i+=2) {
        if(pairs[i][0] > pairs[i + 1][0]) {
            //std::cout << "Front" << std::endl;
            //printIntVectorPurple(pairs[i]);
            //printIntVectorBlue(pairs[i + 1]);
            if(pairs[i].size() < pairs[i + 1].size()) {
                indexHistory.push_back(0);
                //cutLen.push_back(pairs[i].size());
            }
            pairs[i].insert(pairs[i].end(), pairs[i + 1].begin(), pairs[i + 1].end());
            pairs[i + 1].clear();
            if(pairs[i + 1].empty()) {
                pairs.erase(pairs.begin() + i + 1);
                i--;
            }
        }
        else if(pairs[i + 1][0] > pairs[i][0]) {
            //std::cout << "Back" << std::endl;
            //printIntVectorBlue(pairs[i]);
            //printIntVectorPurple(pairs[i + 1]);
            if(pairs[i].size() < pairs[i + 1].size()) {
                indexHistory.push_back(1);
                cutLen.push_back(pairs[i].size());
            }
            pairs[i + 1].insert(pairs[i + 1].end(), pairs[i].begin(), pairs[i].end());
            pairs[i].clear();
            if(pairs[i].empty()) {
                pairs.erase(pairs.begin() + i);
                i--;
            }
        }
    }
    if(impVec.size() != 0) {
        //printIntVectorPurple(impVec);
        cutLen.push_back(impVec.size());
        pairs[pairs.size() - 1].insert(pairs[pairs.size() - 1].end(), impVec.begin(), impVec.end());
        impVec.clear();
        indexHistory.push_back(1);
    }
    
    std::cout << "SIZEVEC: ";
    printLongVector(sizeVec);
    std::cout << "INDEXHISTORY: ";
    printLongVector(indexHistory);
    std::cout << "CUTLEN: ";
    printLongVector(cutLen);
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

bool vecVecIntisSorted(std::vector<std::vector<int> > &vec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        for(unsigned long j = 0; j < vec[i].size() - 1; j++) {
            if(vec[i][j] > vec[i][j + 1])
                return false;
        }
    }
    return true;
}

bool isSorted(std::vector<std::vector<int> > &vec) {
    for(unsigned long i = 0; i < vec.size() - 1; i++) {
        if(vec[i][0] > vec[i + 1][0]) {
            printIntVector(vec[i]);
            return false;
        }
    }
    return true;
}

/* bool checkIfSizeIsVecSize(std::vector<std::vector<int> > &vec, std::vector<unsigned long> &sizeVec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        if(vec[i].size() != sizeVec[sizeVec.size() - 1])
            return false;
    }
    return true;
} */

//check if in vector is pairs[i].size() == sizeVec[sizeVec.size() - 1]
bool Pmerge::checkIfSizeIsVecSize(unsigned long size) {
    for(unsigned long i = 0; i < pairs.size(); i++) {
        if(pairs[i].size() != size)
            return false;
    }
    return true;
}

void preSort(std::vector<std::vector<int> > &vec) {
    if(vec.size() == 3) {
        if(vec[0][0] > vec[1][0]) {
            std::swap(vec[0], vec[1]);
        }
        if(vec[1][0] > vec[2][0]) {
            std::swap(vec[1], vec[2]);
        }
        if(vec[0][0] > vec[1][0]) {
            std::swap(vec[0], vec[1]);
        }
    }
    else if(vec.size() == 2) {
        if(vec[0][0] > vec[1][0]) {
            std::swap(vec[0], vec[1]);
        }
    }

}

/*std::vector<std::vector<int> > ::iterator findPosition(std::vector<std::vector<int> > &vec, ) {
    std::vector<std::vector<int> >::iterator it = std::lower_bound(vec.begin(), vec.end(), impVec);
    return it;
} */

void Pmerge::recSort() {
    /* if(pairs.size() == 1) {
        if(sizeVec.size() > 1 || sizeVec[sizeVec.size() - 1] != 0) {
            if(sizeVec[sizeVec.size() - 1] == sizeVec[sizeVec.size() - 2]) {
                std::cout << "Here1" << std::endl;
                unsigned long pairSize = pairs[0].size() / sizeVec[sizeVec.size() - 1];
                for(unsigned long j = 0; j < pairSize; j++) {
                        for (unsigned long i = 0; i < sizeVec[sizeVec.size() - 1]; i++) {
                            impVec.insert(impVec.begin(), pairs[pairs.size() - 1].back());
                            pairs[pairs.size() - 1].pop_back();
                        }
                        if(j == 0) {
                            tmp.insert(tmp.begin(), impVec);
                            impVec.clear();
                        } else {
                            std::vector<std::vector<int> >::iterator it = std::lower_bound(tmp.begin(), tmp.end(), impVec);
                            tmp.insert(it, impVec);
                            impVec.clear();
                        }
                    }
            std::cout << "PrintVecVector" << std::endl;
            printVecVector(tmp);
            pairs = tmp;
            tmp.clear();
            }
            else {
                for(unsigned long i = 0; i < sizeVec[sizeVec.size() - 1]; i++) {
                    impVec.insert(impVec.begin(), pairs[pairs.size() - 1].back());
                    pairs[pairs.size() - 1].pop_back();
                }
                pairs.insert(pairs.begin() + 1, impVec);
                impVec.clear();
                std::cout << "SizeVec: " << sizeVec[sizeVec.size() - 2] << std::endl;
                std::cout << "PairsSize: " << pairs[0].size() << std::endl;
                if(pairs[0].size() / sizeVec[sizeVec.size() - 2] == 2) {
                    secondSort(secondPair, 0);
                    pairs.erase(pairs.begin());
                    std::vector<std::vector<int> >::iterator it = std::lower_bound(pairs.begin(), pairs.end(), secondPair[0]);
                    pairs.insert(pairs.begin() + 1, secondPair[1]);
                    pairs.insert(it, secondPair[0]);;
                    secondPair.clear();
                }
            }
        }
        //return;
    } */
    if(pairs.size() > 1)
    {
        if(pairs.size() == 2 || pairs.size() == 3) {
            if(!isSorted(pairs)) {
                preSort(pairs);
            }
        }
        std::cout << "sizeVec: ";
        printLongVector(sizeVec);
        std::cout << "cutLen: ";
        printLongVector(cutLen);
        //printLongVector(indexHistory);
                printVecVector(pairs);
        //unsigned long size = pairs.size();
        for(unsigned long i = 0; i < pairs.size(); i++) { //maybe change back to i < size
            if(!pairs.empty() && !sizeVec.empty() && pairs[i].size() == sizeVec[sizeVec.size() - 2]) {
                if(vecVecIntisSorted(pairs)) {
                    std::cout << "Sorted" << std::endl;
                    return;
                }
                printVecVector(secondPair);
                secondSort(secondPair, i);
                pairs.erase(pairs.begin() + i);
                std::vector<std::vector<int> >::iterator it = std::lower_bound(pairs.begin(), pairs.begin() + i, secondPair[0]);
                pairs.insert(pairs.begin() + i, secondPair[1]);
                pairs.insert(it, secondPair[0]);
                i++;
                //size++;
                secondPair.clear();

            } else if (pairs[i].size() == sizeVec[sizeVec.size() - 1]) {
                if(sizeVec.size() > 1 || sizeVec[sizeVec.size() - 3] != 0) {
                    if(!indexHistory.empty() && indexHistory[indexHistory.size() - 1] == 1) {
                        std::cout << "Here Z.320" << std::endl;
                        for (unsigned long j = 0; j < cutLen[cutLen.size() - 1]; j++) {
                            impVec.insert(impVec.begin(), pairs[i].back());
                            pairs[i].pop_back();
                        }
                        std::vector<std::vector<int> >::iterator it = std::lower_bound(pairs.begin(), pairs.end(), impVec);
                        pairs.insert(it, impVec);
                        impVec.clear();
                        i--;
                        indexHistory.pop_back();
                        cutLen.pop_back();
                    } else {
                        std::cout << "Here Z.335" << std::endl;
                        for (unsigned long j = 0; j < sizeVec[sizeVec.size() - 3]; j++) {
                            impVec.insert(impVec.begin(), pairs[i].back());
                            pairs[i].pop_back();
                        }
                        std::vector<std::vector<int> >::iterator it = std::lower_bound(pairs.begin(), pairs.end(), impVec);
                        pairs.insert(it, impVec);
                        impVec.clear();
                        i--;
                        indexHistory.pop_back();
                    }
                }
            }
        }
                sizeVec.pop_back();
                sizeVec.pop_back();
        std::cout << "......................................" << std::endl;
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
    recSort();
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
    //return;
    std::cout << "****************3.Step****************" << std::endl;
    std::cout << "SizeVec.size(): " << sizeVec.size() << std::endl;
    //sizeVec.pop_back();
    //sizeVec.pop_back();
    std::cout << "Level 1" << std::endl;
    recSort();
    if(impInt != -1) {
        impVec.push_back(impInt);
        std::vector<std::vector<int> >::iterator it = std::lower_bound(pairs.begin(), pairs.end(), impVec);
        pairs.insert(it, impVec);
        impVec.clear();
    }
    printVecVector(pairs);
    std::cout << "Pairs.size: " << pairs.size() << std::endl;
    if(isSorted(pairs)) {
        std::cout << "Sorted" << std::endl;
    }
    else {
        std::cout << "Not sorted" << std::endl;
    }
   /*  std::cout << "Level 2" << std::endl;
    recSort();
    std::cout << "Level 3" << std::endl;
    recSort();
    std::cout << "Level 4" << std::endl;
    recSort(); */
    // recSort();
}

//test case good: 38 4 80 50 51 86 36 5 70 54 69 2 52 17 27 77 84 79 83 21 67 10 96 46 89 41 39 29 71 37 3 60 94 74 18 24 55 15 63 44 76 66 32 40 42 58 6 9 68 47 
//impVec: 76 66 40 32 58 42 9 6 68 47  | 58 42 9 6 68 47 | 68 47 
//test case bad: 13 12 38 2 94 37 87 76 17 56 97 8 20 61 98 29 35 30 39 31 86 25 90 43 5 36 23 81 68 95 49 24 47 3 7 66 27 62 11 82 34 79 91 73 63 71 26 59 60 19
//impVec: 


//test case: 77 - 4 29 83 19 42 14 44 77 55 78 70 84 32 30 69 65 38 88
//test case: 89 - 28 51 24 45 73 75 95 48 42 65 89 63 38 91 81 57 5 84


//574 927 120 907 628 101 286 581 467 380 570 596 14 954 901 297 34 945 242 119 338 499 400 974 220 270 834 164 41 866 465 919 716 947 329 659 208 701 882 875 912 858 836 18 685 841 86 946 225 227 226 332 50 440 760 118 31 494