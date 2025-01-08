#include "PmergeMe.hpp"

unsigned long comparisons = 0;


int compare(std::vector<int> a, std::vector<int> b) {
    comparisons++;
    return a[0] < b[0];
}


Pmerge::Pmerge() {
  impInt = -1;
}

Pmerge::~Pmerge() {
}

void Pmerge::fillVector(char *argv) {
    vec.push_back(atoi(argv));
}

template <typename T>
void printContainer(T &container) {
    for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << "\033[32m" << *it << "\033[0m ";
    }
    std::cout << std::endl;
    std::cout << "\033[32m----------------------------------------------\033[0m" << std::endl;
}

template <typename T>
void printContainerLong(T &container) {
    for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << "\033[33m" << *it << "\033[0m ";
    }
    std::cout << std::endl;
    std::cout << "\033[33m----------------------------------------------\033[0m" << std::endl;
}

template <typename T>
void printContainerOfContainers(T &container) {
    for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
        printContainer(*it);
    }
    std::cout << "______________________________________________" << std::endl;
}

template <typename T>
void printContainerPurple(T &container) {
    for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << "\033[35m" << *it << "\033[0m ";
    }
    std::cout << std::endl;
    std::cout << "\033[35m----------------------------------------------\033[0m" << std::endl;
}

template <typename T>
void printContainerBlue(T &container) {
    for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << "\033[34m" << *it << "\033[0m ";
    }
    std::cout << std::endl;
    std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
}

template <typename T>
void printContainerOfContainersRed(T &container) {
    for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
        printContainerRed(*it);
    }
    std::cout << "______________________________________________" << std::endl;
}

template <typename T>
void printContainerRed(T &container) {
    for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << "\033[31m" << *it << "\033[0m ";
    }
    std::cout << std::endl;
    std::cout << "\033[31m----------------------------------------------\033[0m" << std::endl;
}

template <typename T>
void printContainerOfContainersBlue(T &container) {
    for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
        printContainerBlue(*it);
    }
    std::cout << "______________________________________________" << std::endl;
}

void Pmerge::createNewVec() {
    printContainer(vec);
    if(vec.size() % 2 != 0) {
        impInt = vec.back();
        vec.pop_back();
    }
    std::vector<int> newVec;
    for(unsigned long i = 0; i < vec.size(); i+=2) {
        if(vec[i] > vec[i + 1]) {
            comparisons++;
            newVec.push_back(vec[i]);
            newVec.push_back(vec[i + 1]);
        }
        else {
            comparisons++;
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
    printContainerOfContainers(pairs);
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
            comparisons++;
            if(pairs[i].size() < pairs[i + 1].size()) {
                indexHistory.push_back(0);
            }
            pairs[i].insert(pairs[i].end(), pairs[i + 1].begin(), pairs[i + 1].end());
            pairs[i + 1].clear();
            if(pairs[i + 1].empty()) {
                pairs.erase(pairs.begin() + i + 1);
                i--;
            }
        }
        else if(pairs[i + 1][0] > pairs[i][0]) {
            comparisons++;
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
        cutLen.push_back(impVec.size());
        pairs[pairs.size() - 1].insert(pairs[pairs.size() - 1].end(), impVec.begin(), impVec.end());
        impVec.clear();
        indexHistory.push_back(1);
    }
    recPairs();
} 

unsigned long jacobsthal(unsigned long n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    unsigned long prev2 = 0, prev1 = 1, current = 0;
    for (unsigned long i = 2; i <= n; ++i) {
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

void Pmerge::secondSort(std::vector<std::vector<int> > &tmp, unsigned long i) {
    divideInHalf(pairs[i]);
    tmp.push_back(second_half);
    tmp.push_back(first_half);
    second_half.clear();
    first_half.clear();
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
            printContainer(vec[i]);
            return false;
        }
    }
    return true;
}

void preSort(std::vector<std::vector<int> > &vec) {
    if(vec.size() == 3) {
        if(vec[0][0] > vec[1][0]) {
            comparisons++;
            std::swap(vec[0], vec[1]);
        }
        if(vec[1][0] > vec[2][0]) {
            comparisons++;
            std::swap(vec[1], vec[2]);
        }
        if(vec[0][0] > vec[1][0]) {
            comparisons++;
            std::swap(vec[0], vec[1]);
        }
    }
    else if(vec.size() == 2) {
        if(vec[0][0] > vec[1][0]) {
            comparisons++;
            std::swap(vec[0], vec[1]);
        }
    }
}

//bool checkIf

void Pmerge::create_jacobsthal_vec(unsigned long size) {
    jaTaVec.resize(size, -1);
    std::vector <unsigned long> tmp;
    if(size == 0)
        return;
    if(size == 1) {
        tmp.push_back(jacobsthal(0));
    }
    if(size == 2) {
        tmp.push_back(jacobsthal(0));
        tmp.push_back(jacobsthal(1));
    } else {
        tmp.push_back(jacobsthal(0));
        tmp.push_back(jacobsthal(1));
        for(unsigned long i = 3; i <= size; i++) {
            if(jacobsthal(i) >= size) {
                if(jacobsthal(i) == size - 1)
                    tmp.push_back(size);
                else
                    tmp.push_back(size - 1);
                break;
            }
            tmp.push_back(jacobsthal(i));
        }
    }
    // std::cout << "Tmp:";
    // printContainerLong(tmp);
    for(unsigned long i = 0; i < jaTaVec.size(); i++) {
        jaTaVec[0] = 0;
        for(unsigned long j = 0; j < tmp.size(); j++) {
            if(j >= 1 && i < jaTaVec.size() - 1 && i == tmp[j - 1]) {
                jaTaVec[i + 1] = tmp[j];
            }
        }
        if(jaTaVec[i] == -1) {
            jaTaVec[i] = jaTaVec[i - 1] - 1;
        }
    }
}

void Pmerge::recSort() {
    /* printVecVectorBlue(pairs);
    std::cout << "Pairs.size: " << pairs.size() << std::endl; */
    create_jacobsthal_vec(pairs.size());
   /*  std::cout << "JaTaVec: ";
    printIntVectorPurple(jaTaVec);
    std::cout << "JaTa.Size: " << jaTaVec.size() << std::endl; */
    if(pairs.size() > 1)
    {
        if(pairs.size() == 2 || pairs.size() == 3) {
            if(!isSorted(pairs)) {
                preSort(pairs);
            }
        }
        for(unsigned long k = 0; k < jaTaVec.size(); k++) { //maybe change back to i < size
            for(unsigned long i = jaTaVec[k]; i < pairs.size(); i++) {
                if(!pairs.empty() && !sizeVec.empty() && pairs[i].size() == sizeVec[sizeVec.size() - 2]) {
                    if(vecVecIntisSorted(pairs)) {
                        std::cout << "Sorted" << std::endl;
                        return;
                    }
                    secondSort(secondPair, i);
                    pairs.erase(pairs.begin() + i);
                    std::vector<std::vector<int> >::iterator it = std::lower_bound(pairs.begin(), pairs.begin() + i, secondPair[0], compare);
                    pairs.insert(pairs.begin() + i, secondPair[1]);
                    pairs.insert(it, secondPair[0]);
                    i++;
                    secondPair.clear();

                } else if (pairs[i].size() == sizeVec[sizeVec.size() - 1]) {
                    if(sizeVec.size() > 1 || sizeVec[sizeVec.size() - 3] != 0) {
                        if(!indexHistory.empty() && indexHistory[indexHistory.size() - 1] == 1) {
                            for (unsigned long j = 0; j < cutLen[cutLen.size() - 1]; j++) {
                                impVec.insert(impVec.begin(), pairs[i].back());
                                pairs[i].pop_back();
                            }
                            std::vector<std::vector<int> >::iterator it = std::lower_bound(pairs.begin(), pairs.end(), impVec, compare);
                            pairs.insert(it, impVec);
                            impVec.clear();
                            i--;
                            indexHistory.pop_back();
                            cutLen.pop_back();
                        } else {
                            for (unsigned long j = 0; j < sizeVec[sizeVec.size() - 3]; j++) {
                                impVec.insert(impVec.begin(), pairs[i].back());
                                pairs[i].pop_back();
                            }
                            std::vector<std::vector<int> >::iterator it = std::lower_bound(pairs.begin(), pairs.end(), impVec, compare);
                            pairs.insert(it, impVec);
                            impVec.clear();
                            i--;
                            indexHistory.pop_back();
                        }
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

void Pmerge::triple_sort(){
    if(vec.size() == 3) {
        if(vec[0] > vec[1]) {
            comparisons++;
            std::swap(vec[0], vec[1]);
        }
        if(vec[1] > vec[2]) {
            comparisons++;
            std::swap(vec[1], vec[2]);
        }
        if(vec[0] > vec[1]) {
            comparisons++;
            std::swap(vec[0], vec[1]);
        }
    }
    if(vec.size() == 2) {
        if(vec[0] > vec[1]) {
            comparisons++;
            std::swap(vec[0], vec[1]);
        }
    }
}


void Pmerge::run() {
    std::cout << "****************1.Step****************" << std::endl;
    if(vec.size() <= 3) {
        triple_sort();
        printContainer(vec);
        //return;
    } else {
        createNewVec();
        printContainerOfContainers(pairs);
        recPairs();
        std::cout << "****************2.Step****************" << std::endl;
        std::cout << "Level 1" << std::endl;
        recSort();
        if(impInt != -1) {
            impVec.push_back(impInt);
            std::vector<std::vector<int> >::iterator it = std::lower_bound(pairs.begin(), pairs.end(), impVec, compare);
            pairs.insert(it, impVec);
            impVec.clear();
        }
        std::cout << "****************3.Step****************" << std::endl;
        printContainerOfContainers(pairs);
        if(isSorted(pairs)) {
            std::cout << "Sorted" << std::endl;
        }
        else {
            std::cout << "Not sorted" << std::endl;
        }
    }
    std::cout << "\033[35mComparisons: " << comparisons << "\033[0m" << std::endl;
}


///////////////////////////////////////////////////////////////
//////////////////////////DEQUE///////////////////////////////
///////////////////////////////////////////////////////////////

