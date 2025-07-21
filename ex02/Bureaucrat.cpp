/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:04:40 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/21 14:13:38 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : name("Unknown"), grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        // Note: name is const, so we can't copy it
        // We can only copy non-const members
        this->grade = other.grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
    if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

int Bureaucrat::getGrade() const
{
    return grade;
}

std::string Bureaucrat::getName() const
{
    return name;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
    std::cout << "GradeTooHighException constructor called" << std::endl;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
    std::cout << "GradeTooLowException constructor called" << std::endl;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

void Bureaucrat::incrementGrade(int amount)
{
    if((grade - amount) < 1)
        throw Bureaucrat::GradeTooHighException();
    else if((grade - amount) > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade -= amount;
}

void Bureaucrat::decrementGrade(int amount)
{
    if((grade + amount) > 150)
        throw Bureaucrat::GradeTooLowException();
    else if((grade + amount) < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        grade += amount;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
    }
}

