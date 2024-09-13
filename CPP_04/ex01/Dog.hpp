#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
    private:
        Brain* _brain;
    public:
        Dog();
        Dog(const Dog &b);
        ~Dog();
        Dog& operator=(const Dog& other);

        void makeSound() const;
        void setTought(std::string idea, int i);
        std::string getTought(int i);
};

#endif