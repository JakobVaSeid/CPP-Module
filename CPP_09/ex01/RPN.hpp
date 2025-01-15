#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <list>


# define DIVISION 1
# define MULTIPLICATION 2
# define SUBTRACTION 3
# define ADDITION 4

bool check_number(std::string num);
bool check_number(char num);
bool check_operator(std::string op);
bool check_operator(char op);
int which_op(std::string op);
bool check_result(long long result);
void calculate(std::stack<int, std::list<int> > &stack, std::string op);
void count_arguments(int argc, char **argv);
void count_arguments(std::string argv);
void rpn(std::string argv, std::stack<int, std::list<int> > &stack);
