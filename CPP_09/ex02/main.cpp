#include "PmergeMe.hpp"

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
                return 1;
            } else {
                for(i = 1; i < argc; i++) {
                    if(!isValidInput(argv[i])) {
                        std::cerr << "Invalid input!" << std::endl;
                        return 1;
                    }
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
        double duration = (double)(end - start) * 1e3 / CLOCKS_PER_SEC;
        std::cout << "\033[33mVec-Time: " << duration << " ms" << " for: " << argc - 1 << " elements" << "\033[0m" << std::endl;
    }
    std::cout << "\033[35m--------------------------------------------------------------------------------------\033[0m" << std::endl;
    {
        clock_t start = clock();
        for (volatile int i = 0; i < 100000000; ++i){
            Pmerge progDeq;
            if(argc < 2) {
                std::cerr << "Not enought arguments!" << std::endl;
                return 1;
            } else {
                for(int i = 1; i < argc; i++) {
                    if(!isValidInput(argv[i])) {
                        std::cerr << "Invalid input!" << std::endl;
                        return 1;
                    }
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
        double duration = (double)(end - start) * 1e3 / CLOCKS_PER_SEC;
        std::cout << "\033[33mDeq-Time: " << duration << " ms" << " for: " << argc - 1 << " elements" << "\033[0m" << std::endl;
    }
        return 0;
}
