#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void){
    {
        try{
            Bureaucrat A("Herbert", 149);
            Bureaucrat B("Anemarie", 5);
            Bureaucrat C("Gundula", 8);
            
            Intern H;
            
            Form *F = H.makeForm("request", "RoboForm");

            delete F;
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }
    {
        try{
            Bureaucrat A("Herbert", 149);
            Bureaucrat B("Anemarie", 5);
            Bureaucrat C("Gundula", 8);
            
            Intern H;
            
            Form *F = H.makeForm("robotomy request", "RoboForm");

            delete F;
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }
    {
        try{
            Bureaucrat A("Herbert", 149);
            Bureaucrat B("Anemarie", 5);
            Bureaucrat C("Gundula", 8);
            
            Intern H;
            
            Form *F = H.makeForm("shrubbery creation", "RoboForm");
            B.signForm(*F);

            delete F;
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }
    {
        try{
            Bureaucrat A("Herbert", 149);
            Bureaucrat B("Anemarie", 5);
            Bureaucrat C("Gundula", 8);
            
            Intern H;
            
            Form *F = H.makeForm("presidental pardon", "RoboForm");
            A.signForm(*F);

            delete F;
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }
}