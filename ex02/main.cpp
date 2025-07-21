/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:52:58 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/21 14:23:18 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void testShrubberyCreationForm() {
    std::cout << "\n=== TESTING SHRUBBERY CREATION FORM ===" << std::endl;
    
    try {
        ShrubberyCreationForm shrub("garden");
        Bureaucrat lowGrade("LowGrade", 150);
        Bureaucrat midGrade("MidGrade", 140);
        Bureaucrat highGrade("HighGrade", 100);

        std::cout << shrub << std::endl;

        // Test signing
        std::cout << "\n-- Testing signing with insufficient grade --" << std::endl;
        try {
            shrub.beSigned(lowGrade);
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n-- Testing signing with sufficient grade --" << std::endl;
        shrub.beSigned(midGrade);
        std::cout << "Form signed: " << shrub.getIsSigned() << std::endl;

        // Test execution
        std::cout << "\n-- Testing execution --" << std::endl;
        highGrade.executeForm(shrub);

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testRobotomyRequestForm() {
    std::cout << "\n=== TESTING ROBOTOMY REQUEST FORM ===" << std::endl;
    
    try {
        RobotomyRequestForm robot("Marvin");
        Bureaucrat lowGrade("LowGrade", 80);
        Bureaucrat midGrade("MidGrade", 60);
        Bureaucrat highGrade("HighGrade", 30);

        std::cout << robot << std::endl;

        // Test signing and execution
        std::cout << "\n-- Testing signing and execution --" << std::endl;
        robot.beSigned(midGrade);
        std::cout << "Form signed: " << robot.getIsSigned() << std::endl;

        // Test multiple executions to show 50% success rate
        std::cout << "\n-- Testing multiple executions (50% success rate) --" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << "\nExecution attempt " << (i + 1) << ":" << std::endl;
            highGrade.executeForm(robot);
        }

        // Test with insufficient execution grade
        std::cout << "\n-- Testing execution with insufficient grade --" << std::endl;
        lowGrade.executeForm(robot);

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testPresidentialPardonForm() {
    std::cout << "\n=== TESTING PRESIDENTIAL PARDON FORM ===" << std::endl;
    
    try {
        PresidentialPardonForm pardon("Arthur Dent");
        Bureaucrat lowGrade("LowGrade", 30);
        Bureaucrat midGrade("MidGrade", 20);
        Bureaucrat highGrade("HighGrade", 1);

        std::cout << pardon << std::endl;

        // Test signing with insufficient grade
        std::cout << "\n-- Testing signing with insufficient grade --" << std::endl;
        try {
            pardon.beSigned(lowGrade);
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        // Test signing with sufficient grade
        std::cout << "\n-- Testing signing with sufficient grade --" << std::endl;
        pardon.beSigned(midGrade);
        std::cout << "Form signed: " << pardon.getIsSigned() << std::endl;

        // Test execution with insufficient grade
        std::cout << "\n-- Testing execution with insufficient grade --" << std::endl;
        midGrade.executeForm(pardon);

        // Test execution with sufficient grade
        std::cout << "\n-- Testing execution with sufficient grade --" << std::endl;
        highGrade.executeForm(pardon);

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testFormRequirements() {
    std::cout << "\n=== TESTING FORM REQUIREMENTS ===" << std::endl;
    
    // Test that forms have correct grade requirements
    ShrubberyCreationForm shrub("test");
    RobotomyRequestForm robot("test");
    PresidentialPardonForm pardon("test");

    std::cout << "ShrubberyCreationForm - Sign: " << shrub.getGradeToSign() 
              << ", Execute: " << shrub.getGradeToExecute() << std::endl;
    std::cout << "RobotomyRequestForm - Sign: " << robot.getGradeToSign() 
              << ", Execute: " << robot.getGradeToExecute() << std::endl;
    std::cout << "PresidentialPardonForm - Sign: " << pardon.getGradeToSign() 
              << ", Execute: " << pardon.getGradeToExecute() << std::endl;

    // Test unsigned form execution
    std::cout << "\n-- Testing execution of unsigned forms --" << std::endl;
    Bureaucrat supreme("Supreme", 1);
    
    supreme.executeForm(shrub);   // Should fail - not signed
    supreme.executeForm(robot);   // Should fail - not signed
    supreme.executeForm(pardon);  // Should fail - not signed
}

void testPolymorphism() {
    std::cout << "\n=== TESTING POLYMORPHISM ===" << std::endl;
    
    try {
        Bureaucrat supreme("Supreme", 1);
        
        // Create forms using base class pointers
        AForm* forms[3];
        forms[0] = new ShrubberyCreationForm("poly_test");
        forms[1] = new RobotomyRequestForm("poly_robot");
        forms[2] = new PresidentialPardonForm("poly_pardon");

        // Sign and execute all forms polymorphically
        for (int i = 0; i < 3; i++) {
            std::cout << "\n-- Form " << (i + 1) << ": " << forms[i]->getName() << " --" << std::endl;
            forms[i]->beSigned(supreme);
            supreme.executeForm(*forms[i]);
        }

        // Clean up
        for (int i = 0; i < 3; i++) {
            delete forms[i];
        }

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "Testing all three concrete form classes and their interactions" << std::endl;

    testFormRequirements();
    testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
    testPolymorphism();

    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    std::cout << "Check the generated files:" << std::endl;
    std::cout << "- garden_shrubbery.txt (ASCII trees)" << std::endl;
    std::cout << "- poly_test_shrubbery.txt (ASCII trees)" << std::endl;

    return 0;
}