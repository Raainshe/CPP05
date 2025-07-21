/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:38:39 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/21 11:42:01 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{   
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

//getters
std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

//exceptions
AForm::GradeTooHighException::GradeTooHighException()
{
    std::cout << "GradeTooHighException constructor called" << std::endl;
}

AForm::GradeTooLowException::GradeTooLowException()
{
    std::cout << "GradeTooLowException constructor called" << std::endl;
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
    std::cout << "GradeTooHighException destructor called" << std::endl;
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
    std::cout << "GradeTooLowException destructor called" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

//beSigned
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "AForm " << form.getName() << " is signed: " << form.getIsSigned() << " grade to sign: " << form.getGradeToSign() << " grade to execute: " << form.getGradeToExecute();
    return os;
}