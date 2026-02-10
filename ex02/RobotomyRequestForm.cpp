#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default"){
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target){
    std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target){
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    if (this != &other){
        AForm::operator=(other);
        this->_target = other._target;
    }
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    return *this;
}

const std::string RobotomyRequestForm::getTarget() const{
    return this->_target;
}

void RobotomyRequestForm::setTarget(const std::string target){
    this->_target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    if (!this->getIsSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrage() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << "* DRILLING NOISES * BZZZZZT!" << std::endl;

    if (std::rand() % 2)
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Failed to robotomize " << this->_target << "!" << std::endl;
    
}