# pragma once

#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExecute;
    public:
        Form();
        Form (std::string name);
        Form(const Form &b);
        Form& operator=(const Form& other);
    
        void beSigned(Bureaucrat other);

        std::string get_name();
        bool get_signed();
        int get_gradeSign();
        int get_gradeExecute();

};

        std::ostream& operator<<(std::ostream& COUT, Bureaucrat& Bureaucrat);
