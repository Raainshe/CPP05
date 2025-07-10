#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat(const std::string &name, int grade);
        ~Bureaucrat();

        int getGrade() const;
        std::string getName() const;

        class GradeTooHighException : public std::exception
        {
            public:
                GradeTooHighException();
                ~GradeTooHighException() throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                GradeTooLowException();
                ~GradeTooLowException() throw();
        };

        void incrementGrade(int amount);
        void decrementGrade(int amount);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

#endif