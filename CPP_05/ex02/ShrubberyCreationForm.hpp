#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
    private:
        std::string         _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm (std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &b);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const& executor) const;
};