#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

    Animal* animals[20];

    for(int i = 0; i < 20; i++){
        if(i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        if(!animals[i])
            for (int j = 0; j < i; j++)
                delete animals[j];
    }
/* 
    for (int i = 0;i < 20; i++){
        animals[i]->makeSound();
    }
 */
    Dog *a = new Dog();
    Dog *b = new Dog(*a);

    a->setTought("Hello hello", 2);
    std::cout << "Tought: " << b->getTought(2) << std::endl;
    std::cout << "Tought: " << a->getTought(2) << std::endl;

    delete a;
    delete b;

    for(int i = 0; i < 20; i++){
        delete animals[i]; 
    }

}