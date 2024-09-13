#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &b);
        virtual ~Animal();
        Animal& operator=(const Animal& other);

        std::string getType() const;
        void    setType(std::string Type);

        virtual void makeSound() const;
};

#endif