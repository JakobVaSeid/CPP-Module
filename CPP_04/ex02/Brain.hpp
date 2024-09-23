#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain{
    protected:
        std::string ideas[100];
    public:
        Brain();
        Brain(std::string idea);
        Brain(const Brain &b);
        ~Brain();
        Brain& operator=(const Brain& other);
        
        void            setTought(std::string idea, int i);
        std::string     getTought(int i);
};

#endif