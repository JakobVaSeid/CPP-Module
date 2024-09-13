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
    }

    // for (int i = 0;i < 20; i++)
        // animals[i]->makeSound();

    /* Animal* dogCopy = new Dog(*(dynamic_cast<Dog*>(animals[2])));  
 
    animals[2]->setTought("Dogfood", 2);
    std::cout << "Tought: " << animals[2]->getTought(2) << std::endl;
    animals[1]->makeSound();

    std::cout << "Tought: " << dogCopy->getTought(2) << std::endl; */

    for(int i = 0; i < 20; i++){
        delete animals[i]; 
    }

}