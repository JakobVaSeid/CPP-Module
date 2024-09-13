#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    public:
        WrongCat();
        WrongCat(const WrongCat &b);
        ~WrongCat();
        WrongCat& operator=(const WrongCat& other);

        void makeSound() const;
};

#endif