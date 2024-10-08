#include "Bureaucrat.hpp"

int main(void){
    {
        try{
            Bureaucrat A("Herbert", 149);
            Bureaucrat B("Anemarie", 1);
            Bureaucrat C("Gundula", 1);

            std::cout << A << std::endl;
            std::cout << B << std::endl;
            std::cout << C << std::endl;
            
            A.decrementGrade();
            A.decrementGrade();
            C.incrementGrade();
        }
        catch (std::exception &e) {
                std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }
    {
        try{
            Bureaucrat A("Herbert", 149);
            Bureaucrat B("Anemarie", 1);
            Bureaucrat C("Gundula", 1);

            std::cout << C << std::endl;
            
            C.incrementGrade();
        }
        catch (std::exception &e) {
                std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }
    {
        try{
            Bureaucrat A("Herbert", 149);
            Bureaucrat B("Anemarie", 1);
            Bureaucrat C("Gundula", 0);

            std::cout << C << std::endl;
            
            C.incrementGrade();
        }
        catch (std::exception &e) {
                std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }
    {
        try{
            Bureaucrat A("Herbert", 151);

            std::cout << A << std::endl;
            
            A.decrementGrade();
        }
        catch (std::exception &e) {
                std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }
}