#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

// Forward declaration to avoid circular dependency
class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
        // Orthodox Canonical Form
        Bureaucrat();                                    // Default constructor
        Bureaucrat(const Bureaucrat& other);            // Copy constructor
        Bureaucrat& operator=(const Bureaucrat& other); // Copy assignment operator
        ~Bureaucrat();                                   // Destructor

        // Parameterized constructor
        Bureaucrat(const std::string &name, int grade);

        int getGrade() const;
        std::string getName() const;

        class GradeTooHighException : public std::exception
        {
            public:
                GradeTooHighException();
                ~GradeTooHighException() throw();
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                GradeTooLowException();
                ~GradeTooLowException() throw();
                virtual const char* what() const throw();
        };

        void incrementGrade(int amount);
        void decrementGrade(int amount);
        void executeForm(AForm const & form) const;  // New method as required
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif