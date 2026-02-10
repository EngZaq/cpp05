#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#include <cstdlib> 
#include <ctime>   

class RobotomyRequestForm : public AForm {
    private :
        std::string _target;
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

        const std::string getTarget() const;
        void setTarget(const std::string target);

        void execute(Bureaucrat const & executor) const;
};

#endif