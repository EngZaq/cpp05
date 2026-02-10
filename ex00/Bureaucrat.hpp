#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        Bureaucrat(const std::string &name, int grade);

        std::string getName() const;
        int getGrage() const;

        void incrementGrade();
        void decrementGrade();
        
        class GradeIsTwoHigh : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeIsTwoLow : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);


#endif