#include "RPN.hpp"

template <typename T>
void printStack(std::stack<T, std::list<int> > stack) {
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
}

int main (int argc, char**argv) {
    std::stack<int, std::list<int> > stack;
    try
    {
        if (argc == 2) {
            count_arguments(argv[1]);
            rpn(argv[1], stack);
        }
        else if(argc < 4) {
            throw std::runtime_error("Not enough arguments");
        }
        else {
            count_arguments(argc, argv);
            for(int i = 1; i < argc; i++) {
                if(check_number(argv[i])) {
                    stack.push(atoi(argv[i]));
                }
                else if (check_operator(argv[i])) {
                    if(stack.size() >= 2)
                        calculate(stack, argv[i]);
                    else 
                        throw std::runtime_error("Not enough numbers!");
                }
                else
                    throw std::runtime_error("Invalid input");
            }
        }
        printStack(stack);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return (1);
    }
}
