#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void){
    {
        try{
            Bureaucrat A("Herbert", 149);
            Bureaucrat B("Anemarie", 5);
            Bureaucrat C("Gundula", 8);
            //AForm F("Antrag", 6, 1);
            ShrubberyCreationForm F("ShrubberyA");

            std::cout << F << std::endl;

            B.signForm(F);
            B.executeForm(F);
            A.executeForm(F);
            C.signForm(F);
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;

    }
    {
        try {
            Bureaucrat A("Herbert", 149);
            Bureaucrat B("Anemarie", 5);
            Bureaucrat C("Gundula", 8);

            PresidentialPardonForm P("PresidentialA");

            std::cout << P << std::endl;
            
            B.signForm(P);
            B.executeForm(P);
            A.executeForm(P);
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }
    {
        try {
            Bureaucrat A("Herbert", 149);
            Bureaucrat B("Anemarie", 5);
            Bureaucrat C("Gundula", 8);

            RobotomyRequestForm R("RobotomyA");

            std::cout << R << std::endl;

            B.signForm(R);
            B.signForm(R);
            B.executeForm(R);
            A.executeForm(R);
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }
}