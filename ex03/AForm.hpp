/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:38:46 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/21 11:41:51 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        AForm();
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        //exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                GradeTooHighException();
                ~GradeTooHighException() throw();
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                GradeTooLowException();
                ~GradeTooLowException() throw();
                const char *what() const throw();
        };

        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(const Bureaucrat &executor) const = 0; // Pure virtual function makes this abstract
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif