#pragma once

#include <iostream>
#include <exception>
#include <fstream>

class AForm;

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

        int getGrade() const;
        std::string getName() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &form);
        void executeForm(AForm const& form);
        class GradeTooHighException : public std::exception{
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            virtual const char* what() const throw();
        };
};
        std::ostream& operator<<(std::ostream& COUT, Bureaucrat& Bureaucrat);

