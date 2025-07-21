/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:01:48 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/21 15:27:13 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

enum FormType {
    SHRUBBERY = 0,
    ROBOTOMY = 1,
    PARDON = 2,
    UNKNOWN = -1
};

FormType getFormType(const std::string &formName) {
    if (formName == "shrubbery creation") return SHRUBBERY;
    if (formName == "robotomy request") return ROBOTOMY;
    if (formName == "presidential pardon") return PARDON;
    return UNKNOWN;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    switch (getFormType(formName))
    {
        case SHRUBBERY:
            std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
            return new ShrubberyCreationForm(target);
        case ROBOTOMY:
            std::cout << "Intern creates RobotomyRequestForm" << std::endl;
            return new RobotomyRequestForm(target);
        case PARDON:
            std::cout << "Intern creates PresidentialPardonForm" << std::endl;
            return new PresidentialPardonForm(target);
        default:
            throw Intern::FormNotFoundException();
    }
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}