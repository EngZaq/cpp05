#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        AForm();
        AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm &other);
        ~AForm();
        AForm &operator=(const AForm &other);
        const std::string getName() const;
        void setName(const std::string name);
        void setIsSigned(bool isSigned);
        bool getIsSigned() const;
        int getGradeToSign() const;
        void setGradeToSign(const int gradeToSign);
        int getGradeToExecute() const;
        void setGradeToExecute(const int gradeToExecute);

        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        virtual void execute(Bureaucrat const & executor) const = 0;

        void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif