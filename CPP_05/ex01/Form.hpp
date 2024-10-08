# pragma once

#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeReq;
        const int           _gradeExecute;
    public:
        Form();
        Form (std::string name, int gS, int gE);
        Form(const Form &b);
        Form& operator=(const Form& other);
        ~Form();
    
        void beSigned(Bureaucrat other);

        std::string get_name() const;
        bool get_signed() const;
        int get_gradeReq() const;
        int get_gradeExecute() const;

        class GradeTooHighException : public std::exception {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            virtual const char* what() const throw();
        };
};

        std::ostream& operator<<(std::ostream& COUT, Form& form);
