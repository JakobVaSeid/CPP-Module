#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
    _grade = 0;
};

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
    if(grade < 1)
        throw GradeTooHighException();
    else if(grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) {
    *this = b;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if(this != &other){
        //this->_name = other._name;
        this->_grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {

};

std::ostream& operator<<(std::ostream& COUT, Bureaucrat& Bureaucrat){
    COUT << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
    return (COUT);
}

std::string Bureaucrat::getName(){
    return(this->_name);
}

int Bureaucrat::getGrade(){
    return (this->_grade);
}

void Bureaucrat::decrementGrade(){
    if(this->_grade + 1 > 150)
        throw GradeTooLowException();
    else
        this->_grade++;
}

void Bureaucrat::incrementGrade(){
    if(this->_grade - 1 < 1)
        throw GradeTooHighException();
    else
        this->_grade--;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("\033[31m Grade to low! (Bureaucrat)\033[0m");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("\033[31mGrade to high! (Bureaucrat)\033[0m");
}