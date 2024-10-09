#include "AForm.hpp"

AForm::AForm () : _signed (false), _gradeReq(0), _gradeExecute(0) {
    
}

AForm::AForm (std::string name, int gS, int gE) : _name(name), _signed (false), _gradeReq(gS), _gradeExecute(gE) {
    if(_gradeReq < 1 || _gradeExecute < 1)
        throw GradeTooHighException();
    else if(_gradeReq > 150 || _gradeExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &b) : _name(b.get_name()), _gradeReq(b.get_gradeReq()), _gradeExecute(b.get_gradeExecute()) {
    *this = b;
}

AForm::~AForm () {

};

AForm& AForm::operator=(const AForm& other) {
    if(this != &other)
        this->_signed = other._signed;
    return (*this);
}

void AForm::beSigned(Bureaucrat bureau){
    if(bureau.getGrade() < this->get_gradeReq())
        this->_signed = true;
    else
        throw GradeTooLowException();
}

/////////////Getter///////////////////

std::string AForm::get_name() const{
    return (this->_name);
}

bool AForm::get_signed() const{
    return (this->_signed);
}

int AForm::get_gradeReq() const{
    return (this->_gradeReq);
}

int AForm::get_gradeExecute() const{
    return (this->_gradeExecute);
}

//Operator overload

std::ostream& operator<<(std::ostream& COUT, AForm const& AForm){
    COUT << "Name: " << AForm.get_name() << std::endl;
    if(AForm.get_signed())
        COUT << "gradeSign: true" <<  std::endl;
    else if (!AForm.get_signed())
        COUT << "gradeSign: false" << std::endl;
        
    COUT << "gradeSign: " << AForm.get_gradeReq() << std::endl;
    COUT << "gradeExecute: " << AForm.get_gradeExecute() << std::endl;

    return (COUT);
}

//Exception
const char* AForm::GradeTooHighException::what() const throw() {
    return ("\033[31mGrade to high! (F)\033[0m");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("\033[31mGrade to low! (F)\033[0m");
}

const char* AForm::FormNotSigned::what() const throw() {
    return ("\033[31mForm not signed! (F)\033[0m");
}
