#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150){
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Form parameterized constructor called" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){
    std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(){
    std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &other){
    if (this != &other){
        this->_isSigned = other._isSigned;
    }
    std::cout << "Form copy assignment operator called" << std::endl;
    return *this;
}

const std::string Form::getName() const{
    return this->_name;
}

bool Form::getIsSigned() const{
    return this->_isSigned;
}

int Form::getGradeToSign() const{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const{
    return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrage() > this->_gradeToSign)
        throw GradeTooLowException();
    this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form){
    out << "Form " << form.getName() << ", signed: " << form.getIsSigned() << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
    return out;
}

const char* Form::GradeTooHighException::what() const throw(){
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "Grade is too low";
}

