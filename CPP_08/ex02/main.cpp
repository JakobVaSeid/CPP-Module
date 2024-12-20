#include "MutantStack.hpp"

int main()
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << "---------------------" << std::endl;
    {
        MutantStack<int> stackA;
        stackA.push(3);
        stackA.push(2);
        MutantStack<int> stackB(stackA);

        MutantStack<int>::iterator it = stackA.begin();
        MutantStack<int>::iterator ite = stackA.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::cout << "*****************************" << std::endl;
        MutantStack<int>::iterator it2 = stackB.begin();
        MutantStack<int>::iterator ite2 = stackB.end();
        ++it2;
        --it2;
        while (it2 != ite2)
        {
        std::cout << *it2 << std::endl;
        ++it2;
        }
    }
    std::cout << "---------------------" << std::endl;
    {
        std::list <int> l;
        l.push_back(5);
        l.push_back(17);
        std::cout << l.back() << std::endl;
        l.pop_back();
        std::cout << l.size() << std::endl;
        l.push_back(3);
        l.push_back(5);
        l.push_back(737);
        //[...]
        l.push_back(0);
        std::list<int>::iterator it = l.begin();
        std::list<int>::iterator ite = l.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::list<int> s(l);
    }
    return 0;
}