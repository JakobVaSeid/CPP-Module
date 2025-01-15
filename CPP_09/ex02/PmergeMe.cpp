#include "PmergeMe.hpp"
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
    std::cout << std::endl;
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
    //printContainer(vec);
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
    //printContainerOfContainers(pairs);
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
            //printContainer(vec[i]);
            return false;
        }
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
    create_jacobsthal_vec(pairs.size());
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
                    pairs.insert(pairs.begin() + i, secondPair[1]);
                    std::vector<std::vector<int> >::iterator it = std::lower_bound(pairs.begin(), pairs.begin() + i, secondPair[0]);
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
                            std::vector<std::vector<int> >::iterator it = std::lower_bound(pairs.begin(), pairs.end(), impVec);
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
                            std::vector<std::vector<int> >::iterator it = std::lower_bound(pairs.begin(), pairs.end(), impVec);
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
            std::swap(vec[0], vec[1]);
        }
        if(vec[1] > vec[2]) {
            std::swap(vec[1], vec[2]);
        }
        if(vec[0] > vec[1]) {
            std::swap(vec[0], vec[1]);
        }
    }
    if(vec.size() == 2) {
        if(vec[0] > vec[1]) {
            std::swap(vec[0], vec[1]);
        }
    }
}

void Pmerge::run() {
    if(vec.size() <= 3) {
        triple_sort();
        std::cout << "\033[32mResult: \033[0m";
        printContainer(vec);
        std::cout << std::endl;
    } else {
        createNewVec();
        //printContainerOfContainers(pairs);
        recPairs();
        recSort();
        if(impInt != -1) {
            impVec.push_back(impInt);
            std::vector<std::vector<int> >::iterator it = std::lower_bound(pairs.begin(), pairs.end(), impVec);
            pairs.insert(it, impVec);
            impVec.clear();
        }
        std::cout << "\033[32mResult: \033[0m";
        printContainerOfContainers(pairs);
        if(isSorted(pairs)) {
            std::cout << "\033[32mSorted\033[0m" << std::endl;
        }
        else {
            std::cout << "\033[31mNot sorted\033[0m" << std::endl;
        }
    }
}


///////////////////////////////////////////////////////////////
//////////////////////////DEQUE///////////////////////////////
/////////////////////////////////////////////////////////////

void Pmerge::fillDeque(char *argv) {
    deq.push_back(atoi(argv));
}

void Pmerge::createNewDeque() {
    //printContainer(deq);
    if(deq.size() % 2 != 0) {
        impInt = deq.back();
        deq.pop_back();
    }
    std::deque<int> newDeque;
    for(unsigned long i = 0; i < deq.size(); i+=2) {
        if(deq[i] > deq[i + 1]) {
            newDeque.push_back(deq[i]);
            newDeque.push_back(deq[i + 1]);
        }
        else {
            newDeque.push_back(deq[i + 1]);
            newDeque.push_back(deq[i]);
        }
        deqPairs.push_back(newDeque);
        newDeque.clear();
    }
}

void Pmerge::getDequePairSize () {
    int sizeFirst = 0;
    int sizeLast = 0;
    sizeFirst = deqPairs[0].size();
    sizeLast = deqPairs[deqPairs.size() - 1].size();
    sizeDeque.push_back(sizeFirst);
    sizeDeque.push_back(sizeLast);
}

void Pmerge::recDeqPairs() {
    //printContainerOfContainers(deqPairs);
    getDequePairSize();
    if(deqPairs.size() == 2 || deqPairs.size() == 3) {
        return;
    }
    if(deqPairs.size() % 2 != 0) {
        impDeque.insert(impDeque.end(), deqPairs.back().begin(), deqPairs.back().end());
        deqPairs.pop_back();
    }
    for(unsigned long i = 0; i < deqPairs.size(); i+=2) {
        if(deqPairs[i][0] > deqPairs[i + 1][0]) {
            if(deqPairs[i].size() < deqPairs[i + 1].size()) {
                indexHistoryDeque.push_back(0);
            }
            deqPairs[i].insert(deqPairs[i].end(), deqPairs[i + 1].begin(), deqPairs[i + 1].end());
            deqPairs[i + 1].clear();
            if(deqPairs[i + 1].empty()) {
                deqPairs.erase(deqPairs.begin() + i + 1);
                i--;
            }
        }
        else if(deqPairs[i + 1][0] > deqPairs[i][0]) {
            if(deqPairs[i].size() < deqPairs[i + 1].size()) {
                indexHistoryDeque.push_back(1);
                cutLenDeque.push_back(deqPairs[i].size());
            }
            deqPairs[i + 1].insert(deqPairs[i + 1].end(), deqPairs[i].begin(), deqPairs[i].end());
            deqPairs[i].clear();
            if(deqPairs[i].empty()) {
                deqPairs.erase(deqPairs.begin() + i);
                i--;
            }
        }
    }
    if(impDeque.size() != 0) {
        cutLenDeque.push_back(impDeque.size());
        deqPairs[deqPairs.size() - 1].insert(deqPairs[deqPairs.size() - 1].end(), impDeque.begin(), impDeque.end());
        impDeque.clear();
        indexHistoryDeque.push_back(1);
    }
    recDeqPairs();
}

void Pmerge::divideInHalf(std::deque <int> &deq) {
    long half = deq.size() / 2;
    for(int i = 0; i < half; i++) {
        firstDeque.push_back(deq[i]);
    }
    for(unsigned long i = half; i < deq.size(); i++) {
        secondDeque.push_back(deq[i]);
    }
}

void Pmerge::secondSort(std::deque<std::deque<int> > &tmp, unsigned long i) {
    divideInHalf(deqPairs[i]);
    tmp.push_back(secondDeque);
    tmp.push_back(firstDeque);
    secondDeque.clear();
    firstDeque.clear();
}

bool deqDeqIntisSorted(std::deque<std::deque<int> > &deq) {
    for(unsigned long i = 0; i < deq.size(); i++) {
        for(unsigned long j = 0; j < deq[i].size() - 1; j++) {
            if(deq[i][j] > deq[i][j + 1])
                return false;
        }
    }
    return true;
}

bool isSorted(std::deque<std::deque<int> > &deq) {
    for(unsigned long i = 0; i < deq.size() - 1; i++) {
        if(deq[i][0] > deq[i + 1][0]) {
            //printContainer(deq[i]);
            return false;
        }
    }
    return true;
}

void preSort(std::deque<std::deque<int> > &deq) {
    if(deq.size() == 3) {
        if(deq[0][0] > deq[1][0]) {
            std::swap(deq[0], deq[1]);
        }
        if(deq[1][0] > deq[2][0]) {
            std::swap(deq[1], deq[2]);
        }
        if(deq[0][0] > deq[1][0]) {
            std::swap(deq[0], deq[1]);
        }
    }
    else if(deq.size() == 2) {
        if(deq[0][0] > deq[1][0]) {
            std::swap(deq[0], deq[1]);
        }
    }
}

void Pmerge::create_jacobsthal_deq(unsigned long size) {
    jaTaDeque.resize(size, -1);
    std::deque <unsigned long> tmp;
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
    for(unsigned long i = 0; i < jaTaDeque.size(); i++) {
        jaTaDeque[0] = 0;
        for(unsigned long j = 0; j < tmp.size(); j++) {
            if(j >= 1 && i < jaTaDeque.size() - 1 && i == tmp[j - 1]) {
                jaTaDeque[i + 1] = tmp[j];
            }
        }
        if(jaTaDeque[i] == -1) {
            jaTaDeque[i] = jaTaDeque[i - 1] - 1;
        }
    }
}

void Pmerge::recDeqSort() {
    create_jacobsthal_deq(deqPairs.size());
    if(deqPairs.size() > 1)
    {
        if(deqPairs.size() == 2 || deqPairs.size() == 3) {
            if(!isSorted(deqPairs)) {
                preSort(deqPairs);
            }
            
        }
        for(unsigned long k = 0; k < jaTaDeque.size(); k++) {
            for(unsigned long i = jaTaDeque[k]; i < deqPairs.size(); i++) {
                if(!deqPairs.empty() && !sizeDeque.empty() && deqPairs[i].size() == sizeDeque[sizeDeque.size() - 2]) {
                    if(deqDeqIntisSorted(deqPairs)) {
                        std::cout << "Sorted" << std::endl;
                        return;
                    }
                    secondSort(secondPairDeque, i);
                    deqPairs.erase(deqPairs.begin() + i);
                    deqPairs.insert(deqPairs.begin() + i, secondPairDeque[1]);
                    std::deque<std::deque<int> >::iterator it = std::lower_bound(deqPairs.begin(), deqPairs.begin() + i, secondPairDeque[0]);
                    deqPairs.insert(it, secondPairDeque[0]);
                    i++;
                    secondPairDeque.clear();

                } else if (deqPairs[i].size() == sizeDeque[sizeDeque.size() - 1]) {
                    if(sizeDeque.size() > 1 || sizeDeque[sizeDeque.size() - 3] != 0) {
                        if(!indexHistoryDeque.empty() && indexHistoryDeque[indexHistoryDeque.size() - 1] == 1) {
                            for (unsigned long j = 0; j < cutLenDeque[cutLenDeque.size() - 1]; j++) {
                                impDeque.insert(impDeque.begin(), deqPairs[i].back());
                                deqPairs[i].pop_back();
                            }
                            std::deque<std::deque<int> >::iterator it = std::lower_bound(deqPairs.begin(), deqPairs.end(), impDeque);
                            deqPairs.insert(it, impDeque);
                            impDeque.clear();
                            i--;
                            indexHistoryDeque.pop_back();
                            cutLenDeque.pop_back();
                        } else {
                            for (unsigned long j = 0; j < sizeDeque[sizeDeque.size() - 3]; j++) {
                                impDeque.insert(impDeque.begin(), deqPairs[i].back());
                                deqPairs[i].pop_back();
                            }
                            std::deque<std::deque<int> >::iterator it = std::lower_bound(deqPairs.begin(), deqPairs.end(), impDeque);
                            deqPairs.insert(it, impDeque);
                            impDeque.clear();
                            i--;
                            indexHistoryDeque.pop_back();
                        }
                
                    }
                }
            }
        }
                sizeDeque.pop_back();
                sizeDeque.pop_back();
        for(unsigned long i = 0; i < impDeque.size(); i++) {
            deqPairs[deqPairs.size() - 1].push_back(impDeque[i]);
            impDeque.pop_back();
            impDeque.erase(impDeque.begin() + i);
        }
    }
    unsigned long counter = 0;
    for(unsigned long i = 0; i < deqPairs.size(); i++) {
        if(deqPairs[i].size() == 1)
            counter++;
        if(counter + 2 == deqPairs.size())
            return;
    }
    recDeqSort();
}

void Pmerge::triple_sort_deq() {
    if(deq.size() == 3) {
        if(deq[0] > deq[1]) {
            std::swap(deq[0], deq[1]);
        }
        if(deq[1] > deq[2]) {
            std::swap(deq[1], deq[2]);
        }
        if(deq[0] > deq[1]) {
            std::swap(deq[0], deq[1]);
        }
    }
    if(deq.size() == 2) {
        if(deq[0] > deq[1]) {
            std::swap(deq[0], deq[1]);
        }
    }
}

void Pmerge::runDeq() {
    if(deq.size() <= 3) {
        triple_sort_deq();
        std::cout << "\033[32mResult: \033[0m";
        printContainer(deq);
        std::cout << std::endl;
    } else {
        createNewDeque();
        recDeqPairs();
        recDeqSort();
        if(impInt != -1) {
            impDeque.push_back(impInt);
            std::deque<std::deque<int> >::iterator it = std::lower_bound(deqPairs.begin(), deqPairs.end(), impDeque);
            deqPairs.insert(it, impDeque);
            impDeque.clear();
        }
        std::cout << "\033[32mResult: \033[0m";
        printContainerOfContainers(deqPairs);
        if(isSorted(deqPairs)) {
            std::cout << "\033[32mSorted\033[0m" << std::endl;
        }
        else {
            std::cout << "\033[31mNot sorted\033[0m" << std::endl;
        }
    }
}
