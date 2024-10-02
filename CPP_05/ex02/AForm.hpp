# pragma once

#include "Bureaucrat.hpp"

class AForm {
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeReq;
        const int           _gradeExecute;
    public:
        AForm();
        AForm (std::string name, int gS, int gE);
        AForm(const AForm &b);
        ~AForm ();
        AForm& operator=(const AForm& other);
    
        virtual void beSigned(Bureaucrat other);

        std::string get_name() const;
        bool get_signed() const;
        int get_gradeReq() const;
        int get_gradeExecute() const;
        virtual void execute(Bureaucrat const& executor) const = 0;

        class GradeTooHighException : public std::exception {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            virtual const char* what() const throw();
        };
        class FormNotSigned : public std::exception {
            virtual const char* what() const throw();
        };
};

        std::ostream& operator<<(std::ostream& COUT, AForm const& Aform);
