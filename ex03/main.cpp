/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:22:50 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/21 15:25:50 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

void testDefaultConstructor() {
    std::cout << "\n=== TESTING DEFAULT CONSTRUCTOR ===" << std::endl;
    Intern intern;
    std::cout << "Default constructor test completed" << std::endl;
}

void testCopyConstructor() {
    std::cout << "\n=== TESTING COPY CONSTRUCTOR ===" << std::endl;
    Intern original;
    std::cout << "\nCreating copy..." << std::endl;
    Intern copy(original);
    std::cout << "Copy constructor test completed" << std::endl;
}

void testAssignmentOperator() {
    std::cout << "\n=== TESTING ASSIGNMENT OPERATOR ===" << std::endl;
    Intern intern1;
    Intern intern2;
    
    std::cout << "\nTesting assignment..." << std::endl;
    intern2 = intern1;
    
    std::cout << "\nTesting self-assignment..." << std::endl;
    intern1 = intern1;
    
    std::cout << "Assignment operator test completed" << std::endl;
}

void testMakeFormValid() {
    std::cout << "\n=== TESTING MAKEFORM - VALID FORMS ===" << std::endl;
    Intern intern;
    AForm* forms[3];
    
    try {
        // Test ShrubberyCreationForm
        std::cout << "\n-- Creating Shrubbery Form --" << std::endl;
        forms[0] = intern.makeForm("shrubbery creation", "ryan");
        if (forms[0]) {
            std::cout << "Form created: " << forms[0]->getName() << std::endl;
        }
        
        // Test RobotomyRequestForm
        std::cout << "\n-- Creating Robotomy Form --" << std::endl;
        forms[1] = intern.makeForm("robotomy request", "glen");
        if (forms[1]) {
            std::cout << "Form created: " << forms[1]->getName() << std::endl;
        }
        
        // Test PresidentialPardonForm
        std::cout << "\n-- Creating Presidential Pardon Form --" << std::endl;
        forms[2] = intern.makeForm("presidential pardon", "gregory");
        if (forms[2]) {
            std::cout << "Form created: " << forms[2]->getName() << std::endl;
        }
        
        // Clean up
        for (int i = 0; i < 3; i++) {
            delete forms[i];
        }
        
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
}

void testMakeFormInvalid() {
    std::cout << "\n=== TESTING MAKEFORM - INVALID FORMS ===" << std::endl;
    Intern intern;
    
    std::string invalidForms[] = {
        "invalid form",
        "shrubbery",  // partial match
        "SHRUBBERY CREATION",  // wrong case
        "robotomy",  // partial match
        "",  // empty string
        "presidential",  // partial match
    };
    
    for (int i = 0; i < 6; i++) {
        std::cout << "\n-- Testing invalid form: \"" << invalidForms[i] << "\" --" << std::endl;
        try {
            AForm* form = intern.makeForm(invalidForms[i], "target");
            std::cout << "ERROR: Should have thrown exception!" << std::endl;
            delete form;
        } catch (const Intern::FormNotFoundException& e) {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Caught unexpected exception: " << e.what() << std::endl;
        }
    }
}

void testFormsIntegration() {
    std::cout << "\n=== TESTING FORMS INTEGRATION ===" << std::endl;
    Intern intern;
    Bureaucrat supreme("Supreme", 1);
    
    try {
        // Create and test each form type
        std::cout << "\n-- Integration Test: Shrubbery --" << std::endl;
        AForm* shrub = intern.makeForm("shrubbery creation", "office");
        if (shrub) {
            shrub->beSigned(supreme);
            supreme.executeForm(*shrub);
            delete shrub;
        }
        
        std::cout << "\n-- Integration Test: Robotomy --" << std::endl;
        AForm* robot = intern.makeForm("robotomy request", "intern");
        if (robot) {
            robot->beSigned(supreme);
            supreme.executeForm(*robot);
            delete robot;
        }
        
        std::cout << "\n-- Integration Test: Presidential Pardon --" << std::endl;
        AForm* pardon = intern.makeForm("presidential pardon", "student");
        if (pardon) {
            pardon->beSigned(supreme);
            supreme.executeForm(*pardon);
            delete pardon;
        }
        
    } catch (const std::exception& e) {
        std::cout << "Exception during integration test: " << e.what() << std::endl;
    }
}

void testExceptionClass() {
    std::cout << "\n=== TESTING EXCEPTION CLASS ===" << std::endl;
    
    try {
        throw Intern::FormNotFoundException();
    } catch (const Intern::FormNotFoundException& e) {
        std::cout << "FormNotFoundException what(): " << e.what() << std::endl;
    }
    
    // Test exception inheritance
    try {
        throw Intern::FormNotFoundException();
    } catch (const std::exception& e) {
        std::cout << "Caught as std::exception: " << e.what() << std::endl;
    }
}

void testDestructor() {
    std::cout << "\n=== TESTING DESTRUCTOR ===" << std::endl;
    std::cout << "Creating intern in scope..." << std::endl;
    {
        Intern intern;
        std::cout << "Intern created in scope" << std::endl;
    }
    std::cout << "Intern should be destroyed when leaving scope" << std::endl;
}

int main()
{
    std::cout << "=== EX03 INTERN CLASS COMPREHENSIVE TESTING ===" << std::endl;
    
    testDefaultConstructor();
    testCopyConstructor();
    testAssignmentOperator();
    testMakeFormValid();
    testMakeFormInvalid();
    testExceptionClass();
    testFormsIntegration();
    testDestructor();
    
    std::cout << "\n=== ALL INTERN TESTS COMPLETED ===" << std::endl;
    std::cout << "Check generated files:" << std::endl;
    std::cout << "- office_shrubbery.txt" << std::endl;
    std::cout << "- Forms were created and executed successfully!" << std::endl;
    
    return 0;
}