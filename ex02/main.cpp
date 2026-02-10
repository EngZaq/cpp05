#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // Seed random number generator for Robotomy
    std::srand(std::time(0));

    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        // Create specific forms
        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Criminal");

        // Intern tries to execute (Fail: not signed)
        intern.executeForm(shrub);

        // Boss signs everything
        boss.signForm(shrub);
        boss.signForm(robot);
        boss.signForm(pardon);

        // Intern tries to execute again (Fail: grade too low)
        intern.executeForm(shrub); // Might succeed (exec grade 137 vs intern 150) -> FAIL
        
        // Boss executes
        boss.executeForm(shrub); // Creates file
        boss.executeForm(robot); // Drilling noise
        boss.executeForm(pardon); // Zaphod Beeblebrox
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}