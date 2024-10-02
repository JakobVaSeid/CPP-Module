#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void){

    try{
    Bureaucrat A("Herbert", 149);
    Bureaucrat B("Anemarie", 5);
    Bureaucrat C("Gundula", 8);
    //AForm F("Antrag", 6, 1);
    ShrubberyCreationForm F;
    RobotomyRequestForm R;
    PresidentialPardonForm P;

    std::cout << F << std::endl;
    std::cout << P << std::endl;
    std::cout << R << std::endl;
    
    std::cout << A << std::endl;
    std::cout << B << std::endl;
    std::cout << C << std::endl;

    B.signForm(F);
    B.executeForm(F);
    B.signForm(R);
    B.executeForm(R);
    B.signForm(P);
    B.executeForm(P);
    //A.executeForm(F);
    A.executeForm(R);
   // C.signForm(F);
    }
    catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
    }
}