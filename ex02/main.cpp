#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 10);
        Bureaucrat bob("Bob", 150);
        
        Form taxForm("Tax Form", 20, 50);

        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);

        alice.signForm(taxForm);
        
        std::cout << taxForm << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}