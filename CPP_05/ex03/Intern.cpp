#include "Intern.hpp"

Intern::Intern() {

};

Intern::Intern(const Intern &b) {
    *this = b;
}

Intern& Intern::operator=(const Intern& other) {
    if(this != &other){
        //this->_name = other._name;
        *this = other;
    }
    return (*this);
}

Intern::~Intern () {

};

Form *makePresidentalForm (std::string target) {
    Form *form = new PresidentialPardonForm(target);
    return (form);
}

Form *makeRobotomyForm (std::string target) {
    Form *form = new RobotomyRequestForm(target);
    return (form);
}

Form *makeShrubberyForm (std::string target) {
    Form *form = new ShrubberyCreationForm(target);
    return (form);
}

Form* Intern::makeForm(std::string formName, std::string target) {
    try {
        Form *form;
        std::string strings[3] = {"presidental pardon", "robotomy request", "shrubbery creation"};
        Form *(*functions[])(const std::string target) = {&makePresidentalForm, &makeRobotomyForm, &makeShrubberyForm};

        for(int i = 0; i < 3; i++){
            if(formName == strings[i]){
                form = functions[i](target);
                std::cout << "\033[32mIntern creates " << formName << "\033[0m"<< std::endl;
                return (form);
            }
        }
        throw brokenForm();
    }
    catch (Intern::brokenForm &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return (0);
}

const char* Intern::brokenForm::what() const throw(){
    return ("\033[31mForm couldn't be created\033[0m");
}