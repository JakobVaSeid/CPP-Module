#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
    private:
        Brain* _brain;
    public:
        Cat();
        Cat(const Cat &b);
        ~Cat();
        Cat& operator=(const Cat& other);

        void makeSound()const;
        void setTought(std::string idea, int i);
        std::string getTought(int i);
};

#endif