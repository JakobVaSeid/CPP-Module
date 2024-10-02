#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm () : AForm("PresidentialPardonForm", 25, 5), _target("Default") {

}

PresidentialPardonForm::PresidentialPardonForm (std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &b) {
    *this = b;
}

PresidentialPardonForm::~PresidentialPardonForm() {

};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if(this != &other)
        this->_target = other._target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const{
        if(!get_signed())
            throw FormNotSigned();
        if(executor.getGrade() > this->get_gradeExecute())
            throw GradeTooLowException();
        else
            std::cout << "\033[32m" << executor.getName() << " executed PresidentialPardonForm" << "\033[0m" << std::endl;

        std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
