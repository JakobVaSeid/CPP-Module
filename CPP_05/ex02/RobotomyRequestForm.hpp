#pragma once

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
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