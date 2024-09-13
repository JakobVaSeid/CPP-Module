#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
j->makeSound();
i->makeSound(); 
meta->makeSound();

const WrongAnimal* wrongMeta = new WrongAnimal();
const WrongAnimal* wrongI = new WrongCat();
const WrongCat wrongCat;

std::cout << wrongI->getType() << " " << std::endl;
wrongI->makeSound(); 
wrongMeta->makeSound();
wrongCat.makeSound();

delete  meta;
delete  j;
delete  i;
delete  wrongI;
delete  wrongMeta;

return 0;
}