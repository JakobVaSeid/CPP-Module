#include "Brain.hpp"

Brain::Brain(){
    //std::cout << "Brain-constructor called!" << std::endl;
    for(int i = 0; i < 100; i++)
        this->ideas[i] = "Default idea!";
};

Brain::Brain(std::string idea){
    for(int i = 0; i < 100; i++)
        this->ideas[i] = idea;
}

Brain::Brain(const Brain &b){
    std::cout << "Copy-constructor Brain!" << std::endl;
    if(this != &b){
        for(int i = 0; i < 100; i++)
            this->ideas[i] = b.ideas[i];
    }
}

Brain::~Brain(){
    //std::cout << "Brain-destructor called!" << std::endl;
}

Brain& Brain::operator=(const Brain& other){
    if(this != &other){
        for(int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

void Brain::setTought(std::string idea, int i){
    this->ideas[i] = idea;
}

std::string Brain::getTought(int i){
    return (this->ideas[i]);
}
