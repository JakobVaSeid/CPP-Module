#include "Form.hpp"

Form::Form () : _gradeExecute(0), _gradeSign(0), _signed (false) {
    
}

Form::Form (std::string name) : _name(name), _gradeExecute(0), _gradeSign(0), _signed (false) {
    
}

Form::Form(const Form &b) {
    *this = b;
}

Form& Form::operator=(const Form& other) {
    if(this != &other){
        //this->_name = other._name;
        //this->_grade = other._grade;
    }
    return (*this);
}

void Form::beSigned(Bureaucrat other){
    if(other.getGrade() > this->get_gradeSign())
        this->_signed = true;
}

/////////////Getter///////////////////

std::string Form::get_name(){
    return (this->_name);
}

bool Form::get_signed(){
    return (this->_signed);
}

int Form::get_gradeSign(){
    return (this->_gradeSign);
}

int Form::get_gradeExecute(){
    return (this->_gradeExecute);
}

///////////////////

std::ostream& operator<<(std::ostream& COUT, Form& form){
    COUT << "Name: " << form.get_name() << std::endl;
    if(form.get_signed())
        COUT << "gradeSign: true" <<  std::endl;
    else
        COUT << "gradeSign: false" << std::endl;
        
    COUT << "gradeSign: " << form.get_gradeSign() << std::endl;
    COUT << "gradeExecute: " << form.get_gradeExecute() << std::endl;

    return (COUT);
}
