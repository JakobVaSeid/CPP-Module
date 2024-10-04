#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){
    {
        try{
            Bureaucrat A("Herbert", 149);
            Bureaucrat B("Anemarie", 5);
            Bureaucrat C("Gundula", 8);
            Form F("Antrag I", 6, 1);
            Form G("Antrag II", 6, 1);

            std::cout << F << std::endl;
            std::cout << A << std::endl;
            std::cout << B << std::endl;
            std::cout << C << std::endl;

            B.signForm(F);
            B.signForm(F);
            C.signForm(G);
        }
        catch (std::exception &e) {
                std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }
    /* {
        try{
            Bureaucrat A("Herbert", 149);
            Bureaucrat B("Anemarie", 5);
            Bureaucrat C("Gundula", 8);
            Form F("Antrag I", 6, 1);
            Form G("Antrag II", 6, 1);


            std::cout << F << std::endl;
            std::cout << A << std::endl;
            std::cout << B << std::endl;
            std::cout << C << std::endl;

            B.signForm(F);
            B.signForm(F);
            C.signForm(G);
        }
        catch (std::exception &e) {
                std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    } */
}