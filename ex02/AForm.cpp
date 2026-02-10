#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150){
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "AForm parameterized constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm(){
    std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other){
    if (this != &other){
        this->_isSigned = other._isSigned;
    }
    std::cout << "AForm copy assignment operator called" << std::endl;
    return *this;
}

const std::string AForm::getName() const{
    return this->_name;
}

bool AForm::getIsSigned() const{
    return this->_isSigned;
}

int AForm::getGradeToSign() const{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const{
    return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrage() > this->_gradeToSign)
        throw GradeTooLowException();
    this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm){
    out << "AForm " << AForm.getName() << ", signed: " << AForm.getIsSigned() << ", grade to sign: " << AForm.getGradeToSign() << ", grade to execute: " << AForm.getGradeToExecute();
    return out;
}

const char* AForm::GradeTooHighException::what() const throw(){
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "Grade is too low";
}

