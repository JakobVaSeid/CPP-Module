#include "PmergeMe.hpp"

//print the vector
void printVector(std::vector<int> &vec) {
    for(unsigned long i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " " << std::endl;
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

/* bool check_input(char *arg) {} */

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

void createNewVec(std::vector<int> &newVec, std::vector<int> &vec) {
    for(unsigned long i = 0; i < vec.size(); i+=2) {
        int num = biggerNum(vec[i], vec[i + 1]);
        if(num == -1)
            continue;
        newVec.push_back(num);
        if(num == vec[i]) {
            vec.erase(vec.begin() + i);
            i--;
        }
        else if(num == vec[i + 1]) {
            vec.erase(vec.begin() + i + 1);
            i--;
        }
    }
}

/* std::vector<int>  */ void pushInNewVec(std::vector<int> &vec1, std::vector<int> &vec2) {
        if(vec1.size() < 2 /* || vec2.size() < 2 */)
            return;
        std::vector<int> newVec1;
        std::vector<int> newVec2;
        //vec2.begin();
        createNewVec(newVec1, vec1);
        pushInNewVec(newVec1, vec1);
        createNewVec(newVec1, vec2);
        printVector(newVec2);
        printVector(vec2);
        printVector(newVec1);
        printVector(vec1);
}



//Jacobsthal sequence
/* int jacobsthal(int n) {
    std::cout << "N: " << n << std::endl;
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return jacobsthal(n - 1) + (2 * jacobsthal(n - 2));
} */

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

int main (int argc, char **argv) {

    //std::vector<std::pair<int, int> >vec;
    std::vector<int> vec;
    std::vector<int> newVec;

    if(argc < 2) {
        std::cerr << "Not enought arguments!" << std::endl;
    } else {
        for(int i = 1; i < argc; i++) {
            vec.push_back(atoi(argv[i]));
            /* if(i + 1 >= argc)
                vec.push_back(std::make_pair(atoi(argv[i]), -1));
            else
                vec.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i + 1]))); */
        }
        //swap_pairs(vec);
        pushInNewVec(vec, newVec);
        //std::sort(vec.begin(), vec.end());
    }
        //long long num = 11;
        //std::cout << "Jacobsthal: " << jacobsthal(num) << std::endl;

    //printVector(vec);
}