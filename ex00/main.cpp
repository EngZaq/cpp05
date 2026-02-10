#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        
        bob.incrementGrade(); // become 1
        std::cout << bob << std::endl;
        
        bob.incrementGrade(); // throw an exception
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-------------------" << std::endl;

    try {
        Bureaucrat jim("Jim", 155); // Should fail immediately
    }
    catch (std::exception &e) {
        std::cout << "Construction failed: " << e.what() << std::endl;
    }

    return 0;
}