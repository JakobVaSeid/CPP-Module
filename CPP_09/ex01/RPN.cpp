#include "RPN.hpp"

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

bool check_result(long long result) {
    return result >= std::numeric_limits<int>::min() && result <= std::numeric_limits<int>::max();
}

void calculate(std::stack<int, std::list<int> > &stack, std::string op) {
    //printStack(stack);
    int num1 = stack.top();
    stack.pop();
    int num2 = stack.top();
    stack.pop();
    long long result = 0;

    if(op == "+") {
        result = static_cast<long long>(num2) + num1;
    }
    else if (op == "-") {
        result = static_cast<long long>(num2) - num1;
    }
    else if (op == "*") {
        result = static_cast<long long>(num2) * num1;
    }
    else if (op == "/") {
        if(num1 == 0)
            throw std::runtime_error("No division with zero allowed!");
        result = static_cast<long long>(num2) / num1;
    }
    if(!check_result(result))
        throw std::runtime_error("Result out of bound!");
    stack.push(result);
    
}

void count_arguments(int argc, char **argv) {
    int numCount = 0;
    int opCount = 0;

    for (int i = 1; i < argc; i++) {
        if(check_number(argv[i]))
            numCount++;
        else if(check_operator(argv[i]))
            opCount++;
        else
            throw std::runtime_error("Invalid input");
    }
    if(numCount != opCount + 1)
        throw std::runtime_error("Invalid input");
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
            throw std::runtime_error("Invalid input");
    }
    if(numCount != opCount + 1)
        throw std::runtime_error("Invalid input");
}

//check stack length
//check amount of numbers compared to operator

void rpn(std::string argv, std::stack<int, std::list<int> > &stack) {
    std::istringstream tokens(argv);
    std::string token;
    while(tokens >> token) {
        if(check_number(token)) {
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
    }
}