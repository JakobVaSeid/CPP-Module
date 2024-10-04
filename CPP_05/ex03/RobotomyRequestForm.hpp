#pragma once

#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form {
    private:
        std::string         _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm (std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &b);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const& executor) const;
};