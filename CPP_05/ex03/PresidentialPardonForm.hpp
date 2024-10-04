#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form {
    private:
        std::string         _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm (std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &b);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const& executor) const;
};