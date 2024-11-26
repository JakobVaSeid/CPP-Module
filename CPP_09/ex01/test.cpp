#include "RPN.hpp"

template <typename T>
void printStack(std::stack<T> stack) {
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
}

bool check_number(std::string num) {
    if(num.length() != 1)
        return (false);
    if(num > "9" || num < "0")
        return (false);
    return (true);
}

bool check_number(char num) {
    if(num > '9' || num < '0')
        return (false);
    return (true);
}

bool check_operator(std::string op) {
    if(op.length() != 1)
        return (false);
    if(op != "+" && op != "-" && op != "*" && op != "/")
        return (false);
    return (true);
}

bool check_operator(char op) {
    if(op != '+' && op != '-' && op != '*' && op != '/')
        return (false);
    return (true);
}

int which_op(std::string op) {
    if(op == "+")
        return (ADDITION);
    else if (op == "-")
        return (SUBTRACTION);
    else if (op == "*")
        return (MULTIPLICATION);
    else if (op == "/")
        return (DIVISION);
    else 
        return (0);
}

void calculate(std::stack<int> &stack, std::string op) {
    printStack(stack);
    int num1 = stack.top();
    std::cout << "Top: " << stack.top() << std::endl;
    stack.pop();
    int num2 = stack.top();
    stack.pop();
    int result;


    if(op == "+") {
        result = num2 + num1;
        stack.push(result);
    }
    else if (op == "-") {
        result = num2 - num1;
        stack.push(result);
    }
    else if (op == "*") {
        result = num2 * num1;
        stack.push(result);
    }
    else if (op == "/") {
        result = num2 / num1;
        stack.push(result);
    }
}

void count_arguments(std::string argv) {
    int numCount = 0;
    int opCount = 0;

    for (std::string::iterator it = argv.begin(); it != argv.end(); it++) {
        if(*it == ' ')
            it++;
        if(check_number(*it))
            numCount++;
        else if(check_operator(*it))
            opCount++;
        else
            throw std::runtime_error("Invalid input1");
    }
    if(numCount != opCount + 1)
        throw std::runtime_error("Number/operator ratio invalid!");
}

//check stack length
//check amount of numbers compared to operator

void rpn(std::string argv) {
    std::istringstream tokens(argv);
    std::string token;
    std::stack<int>stack;
    while(tokens >> token) {
        if(check_number(token)) {
            std::cout << "Is number " << token << std::endl;
            stack.push(atoi(token.c_str()));
        }
        else if (check_operator(token)) {
            if(stack.size() >= 2)
                calculate(stack, token);
            else 
                throw std::runtime_error("Not enough numbers!");
        }
        else
            throw std::runtime_error("Invalid input");
        std::cout << token << std::endl;
    }
    printStack(stack);
}

int main (int argc, char**argv) {
    std::stack<int> stack;
    
    try
    {
        if(argc != 2)
            throw std::runtime_error("Not enough arguments");
        /*else { */
                count_arguments(argv[1]);
                rpn(argv[1]);
            /* count_arguments(argc, argv);
            for(int i = 1; i < argc; i++) {
                if(check_number(argv[i])) {
                    std::cout << "Is number " << argv[i] << std::endl;
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
            } */
        //}
        printStack(stack);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}