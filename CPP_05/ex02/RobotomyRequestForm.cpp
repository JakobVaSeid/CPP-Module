#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm () : AForm("RobotomyRequestForm", 72, 45), _target("Default") {
    
}

RobotomyRequestForm::RobotomyRequestForm (std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &b) {
    *this = b;
}

RobotomyRequestForm::~RobotomyRequestForm() {

};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if(this != &other)
        this->_target = other._target;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const{

        srand(static_cast<unsigned int>(time(0)));
        if(!get_signed())
            throw FormNotSigned();
        if(executor.getGrade() > this->get_gradeExecute())
            throw GradeTooLowException();
        else
            std::cout << "\033[32m" << executor.getName() << " executed RobotomyRequestForm" << "\033[0m" << std::endl;

        if((rand() % 2 )== 0)
            std::cout << _target << " has been robotomized successfully" << std::endl;
        else
            std::cout << "Robotomy failed!" << std::endl;
}