#include "PmergeMe.hpp"

//10er Pairs
//Edge case test: ./PmergeMe 1 2 89 12 23 415 213 78 45 12 36 100 78 123 128 89 612 417 18 14

//check input only positiv numbers and smaller than max int
bool isValidInput(const char* str) {
    if (!str || *str == '\0')
        return false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return false;
    }
    long long num = atoll(str);
    if (num < 0 || num > INT_MAX) 
        return false;
    return true;
}

void printArgv(int argc, char **argv) {
    std::cout << "\033[34mInput: ";
    for(int i = 1; i < argc; i++) {
        std::cout << argv[i] << " ";
    }
    std::cout << "\033[0m" << std::endl;
}

int main (int argc, char **argv) {
    {
        clock_t start = clock();
        
        for (volatile int i = 0; i < 100000000; ++i){
            Pmerge prog;

            if(argc < 2) {
                std::cerr << "Not enought arguments!" << std::endl;
            } else {
                if(!isValidInput(argv[1])) {
                    std::cerr << "Invalid input!" << std::endl;
                    return 1;
                }
                printArgv(argc, argv);
                for(int i = 1; i < argc; i++) {
                    prog.fillVector(argv[i]);
                }
                prog.run();
            }
            break;
        }
        clock_t end = clock();
        double duration = (double)(end - start) * 1e6 / CLOCKS_PER_SEC;
        std::cout << "\033[33mVec-Time: " << duration << " µs" << "for: " << argc - 1 << " elemnts" << "\033[0m" << std::endl;
    }
    std::cout << "\033[35m--------------------------------------------------------------------------------------\033[0m" << std::endl;
    {
        clock_t start = clock();
        for (volatile int i = 0; i < 100000000; ++i){
            Pmerge progDeq;
            if(argc < 2) {
                std::cerr << "Not enought arguments!" << std::endl;
            } else {
                if(!isValidInput(argv[1])) {
                    std::cerr << "Invalid input!" << std::endl;
                    return 1;
                }
                printArgv(argc, argv);
                for(int i = 1; i < argc; i++) {
                    progDeq.fillDeque(argv[i]);
                }
                progDeq.runDeq();
            }
            break;
        }
        clock_t end = clock();
        double duration = (double)(end - start) * 1e6 / CLOCKS_PER_SEC;
        std::cout << "\033[33mDeq-Time: " << duration << " µs" << "for: " << argc - 1 << " elemnts" << "\033[0m" << std::endl;
    }
        return 0;
}

/* int main (int argc, char **argv) {
    clock_t start = clock();

    for (volatile int i = 0; i < 100000000; ++i){
        Pmerge progDeq;
        if(argc < 2) {
            std::cerr << "Not enought arguments!" << std::endl;
        } else {
            if(!isValidInput(argv[1])) {
                std::cerr << "Invalid input!" << std::endl;
                return 1;
            }
            printArgv(argc, argv);
            for(int i = 1; i < argc; i++) {
                progDeq.fillDeque(argv[i]);
            }
            progDeq.runDeq();
        }
        break;
    }
    clock_t end = clock();
    double duration = (double)(end - start) * 1e6 / CLOCKS_PER_SEC;
    std::cout << "Vec-Time: " << duration << " µs" << std::endl;
    return 0;
} */