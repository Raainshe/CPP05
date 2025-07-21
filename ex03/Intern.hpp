/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:59:54 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/21 15:17:49 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShruberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern
{
    public: 
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(const std::string &formName, const std::string &target);
        class FormNotFoundException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif