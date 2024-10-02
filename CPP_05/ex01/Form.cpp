#include "Form.hpp"

Form::Form () : _signed (false), _gradeReq(0), _gradeExecute(0) {
    
}

Form::Form (std::string name, int gS, int gE) : _name(name), _signed (false), _gradeReq(gS), _gradeExecute(gE) {
    
}

Form::Form(const Form &b) : _name(b.get_name()), _gradeReq(b.get_gradeReq()), _gradeExecute(b.get_gradeExecute()) {
    *this = b;
}

Form::~Form() {

};

Form& Form::operator=(const Form& other) {
    if(this != &other)
        this->_signed = other._signed;
    return (*this);
}

void Form::beSigned(Bureaucrat bureau){
    if(bureau.getGrade() <= this->get_gradeReq())
        this->_signed = true;
    else
        throw GradeTooLowException();
}

/////////////Getter///////////////////

std::string Form::get_name() const{
    return (this->_name);
}

bool Form::get_signed() const{
    return (this->_signed);
}

int Form::get_gradeReq() const{
    return (this->_gradeReq);
}

int Form::get_gradeExecute() const{
    return (this->_gradeExecute);
}

//Operator overload

std::ostream& operator<<(std::ostream& COUT, Form& form){
    COUT << "Name: " << form.get_name() << std::endl;
    if(form.get_signed())
        COUT << "gradeSign: true" <<  std::endl;
    else if (!form.get_signed())
        COUT << "gradeSign: false" << std::endl;
        
    COUT << "gradeSign: " << form.get_gradeReq() << std::endl;
    COUT << "gradeExecute: " << form.get_gradeExecute() << std::endl;

    return (COUT);
}

//Exception
const char* Form::GradeTooHighException::what() const throw() {
    return ("\033[31mGrade to high! (F)\033[0m");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("\033[31mGrade to low! (F)\033[0m");
}
