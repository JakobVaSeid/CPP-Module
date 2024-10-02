#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm () : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {
    
}

ShrubberyCreationForm::ShrubberyCreationForm (std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &b) {
    *this = b;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if(this != &other)
        this->_target = other._target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const{
        if(!get_signed())
            throw FormNotSigned();
        if(executor.getGrade() > this->get_gradeExecute())
            throw GradeTooLowException();
        else
            std::cout << "\033[32m" << executor.getName() << " executed ShrubberyCreationForm" << "\033[0m" << std::endl;
        
        std::string extension;

        extension = _target + "_shrubbery";

        std::cout << "Extension: " << extension << std::endl;

        std::ofstream file(extension.c_str());
        if(!file.is_open()) {
            std::cout << "File creation went wrong!" << std::endl;
        }

           file << "              &&& &&  & &&     "  << std::endl;
           file << "   && &\\/&\\|& ()|/ @, &&       "  << std::endl;
           file << "   &\\/(/&/&||/& /_/)_&/        "  << std::endl;
           file << "&() &\\/&|()|/&\\/ '%' & ()      "  << std::endl;
           file << "   &_\\/_&&_/\\/& &\\/&/ &&&      "  << std::endl;
           file << "&&   && & &|&|&&&\\/&/ & &&     "  << std::endl;
           file << "   ()&_---()&\\&\\|&&-&&--%---   "  << std::endl;
           file << "              &&     \\|||      " << std::endl;
           file << "                       |||      "  << std::endl;
           file << "                       |||      "  << std::endl;
           file << "                       |||      "  << std::endl;
           file << "                , -=-~  .-^- _ "  << std::endl;

}