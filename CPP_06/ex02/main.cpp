#include "Base.hpp"

Base* generate(void) {
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0) {
        return (new A);
    } else if (random == 1) {
        return (new B);
    } else {
        return (new C);
    }
}

void identify (Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "Object: A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Object: B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Object: C" << std::endl;
    } else 
        std::cout << "Error!" << std::endl;
}

void identify (Base &p) {
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Belongs to: A" << std::endl;
    } catch (std::exception &e) {
        try {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "Belongs to: B" << std::endl;
        } catch (std::exception &e) {
            try {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "Belongs to: C" << std::endl;
            } catch (std::exception &e) {
                std::cout << "Bad cast!" << std::endl;
            }
        }
    }
}

int main () {
    {
        Base *base = generate();

        identify(base);
        identify(*base);
        delete base;
    }
    {
        Base *test = NULL;

        identify(test);
        identify(*test);
    }
    {
        Base *P = NULL;
        Base *D = P;

        identify(D);
        identify(*D);
    }
    return 0;
}