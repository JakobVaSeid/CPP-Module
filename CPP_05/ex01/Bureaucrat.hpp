#pragma once

#include <iostream>
#include <exception>

class Form;

class Bureaucrat{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &b);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        int getGrade();
        std::string getName();
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &form);
        class GradeTooHighException : public std::exception{
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            virtual const char* what() const throw();
        };
};
        std::ostream& operator<<(std::ostream& COUT, Bureaucrat& Bureaucrat);
