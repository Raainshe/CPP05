/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:04:40 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/10 14:17:55 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
    if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
    std::cout << "GradeTooHighException constructor called" << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
    std::cout << "GradeTooLowException constructor called" << std::endl;
}

void Bureaucrat::incrementGrade(int amount)
{
    if((grade + amount > 150))
        throw Bureaucrat::GradeTooHighException();

    if((grade + amount < 1))
        throw Bureaucrat::GradeTooLowException();

    grade += amount;
}

void Bureaucrat::decrementGrade(int amount)
{
    if((grade - amount > 150))
        throw Bureaucrat::GradeTooHighException();

    if((grade - amount < 1))
        throw Bureaucrat::GradeTooLowException();

    grade -= amount;
}

