#pragma once

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern &b);
        Intern& operator=(const Intern& other);
        ~Intern ();

        Form *makeForm(std::string formName, std::string target);

        class brokenForm : std::exception {
            public:
                virtual const char* what() const throw();
        };

};