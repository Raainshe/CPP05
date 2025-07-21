/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:22:59 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/21 10:40:10 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

void testDefaultConstructor() {
    std::cout << "\n=== Testing Default Constructor ===" << std::endl;
    Form defaultForm;
    std::cout << "Default form: " << defaultForm << std::endl;
    std::cout << "Name: " << defaultForm.getName() << std::endl;
    std::cout << "Is signed: " << defaultForm.getIsSigned() << std::endl;
    std::cout << "Grade to sign: " << defaultForm.getGradeToSign() << std::endl;
    std::cout << "Grade to execute: " << defaultForm.getGradeToExecute() << std::endl;
}

void testParameterizedConstructor() {
    std::cout << "\n=== Testing Parameterized Constructor ===" << std::endl;
    
    try {
        Form validForm("Tax Form", 50, 25);
        std::cout << "Valid form created: " << validForm << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    // Test grade too high (< 1)
    std::cout << "\nTesting grade too high (0):" << std::endl;
    try {
        Form invalidForm("Invalid Form", 0, 50);
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    } catch (const Form::GradeTooHighException& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    // Test grade too low (> 150)
    std::cout << "\nTesting grade too low (151):" << std::endl;
    try {
        Form invalidForm("Invalid Form", 50, 151);
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    // Test boundary values
    std::cout << "\nTesting boundary values (1 and 150):" << std::endl;
    try {
        Form boundaryForm("Boundary Form", 1, 150);
        std::cout << "Boundary form created: " << boundaryForm << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
}

void testCopyConstructor() {
    std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
    
    Form original("Original Form", 75, 100);
    std::cout << "Original: " << original << std::endl;
    
    Form copy(original);
    std::cout << "Copy: " << copy << std::endl;
    
    std::cout << "Testing that copy is independent..." << std::endl;
    // Note: We can't modify const members, but we can test signing
}

void testAssignmentOperator() {
    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    
    Form form1("Form 1", 50, 75);
    Form form2("Form 2", 100, 125);
    
    std::cout << "Before assignment:" << std::endl;
    std::cout << "Form1: " << form1 << std::endl;
    std::cout << "Form2: " << form2 << std::endl;
    
    form2 = form1;
    
    std::cout << "After form2 = form1:" << std::endl;
    std::cout << "Form1: " << form1 << std::endl;
    std::cout << "Form2: " << form2 << std::endl;
    
    // Test self-assignment
    form1 = form1;
    std::cout << "After self-assignment, Form1: " << form1 << std::endl;
}

void testGetters() {
    std::cout << "\n=== Testing Getters ===" << std::endl;
    
    Form testForm("Test Form", 42, 84);
    
    std::cout << "getName(): " << testForm.getName() << std::endl;
    std::cout << "getIsSigned(): " << testForm.getIsSigned() << std::endl;
    std::cout << "getGradeToSign(): " << testForm.getGradeToSign() << std::endl;
    std::cout << "getGradeToExecute(): " << testForm.getGradeToExecute() << std::endl;
}

void testBeSigned() {
    std::cout << "\n=== Testing beSigned Method ===" << std::endl;
    
    Form form("Signing Test", 50, 25);
    std::cout << "Form before signing: " << form << std::endl;
    
    // Test with bureaucrat who can sign (grade <= 50)
    std::cout << "\nTesting with authorized bureaucrat (grade 30):" << std::endl;
    try {
        Bureaucrat authorizedBureaucrat("Alice", 30);
        std::cout << "Bureaucrat: " << authorizedBureaucrat << std::endl;
        form.beSigned(authorizedBureaucrat);
        std::cout << "Form after signing: " << form << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test with bureaucrat who cannot sign (grade > 50)
    std::cout << "\nTesting with unauthorized bureaucrat (grade 75):" << std::endl;
    try {
        Form form2("Another Form", 50, 25);
        Bureaucrat unauthorizedBureaucrat("Bob", 75);
        std::cout << "Bureaucrat: " << unauthorizedBureaucrat << std::endl;
        form2.beSigned(unauthorizedBureaucrat);
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
    
    // Test edge case: exact grade match
    std::cout << "\nTesting with exact grade match (grade 50):" << std::endl;
    try {
        Form form3("Exact Grade Form", 50, 25);
        Bureaucrat exactGradeBureaucrat("Charlie", 50);
        std::cout << "Bureaucrat: " << exactGradeBureaucrat << std::endl;
        form3.beSigned(exactGradeBureaucrat);
        std::cout << "Form after signing: " << form3 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testExceptions() {
    std::cout << "\n=== Testing Exception Classes ===" << std::endl;
    
    // Test GradeTooHighException
    try {
        throw Form::GradeTooHighException();
    } catch (const Form::GradeTooHighException& e) {
        std::cout << "GradeTooHighException what(): " << e.what() << std::endl;
    }
    
    // Test GradeTooLowException
    try {
        throw Form::GradeTooLowException();
    } catch (const Form::GradeTooLowException& e) {
        std::cout << "GradeTooLowException what(): " << e.what() << std::endl;
    }
}

void testStreamOperator() {
    std::cout << "\n=== Testing Stream Output Operator ===" << std::endl;
    
    Form unsignedForm("Unsigned Form", 100, 50);
    std::cout << "Unsigned form: " << unsignedForm << std::endl;
    
    Form signedForm("Signed Form", 75, 25);
    try {
        Bureaucrat signer("Signer", 50);
        signedForm.beSigned(signer);
        std::cout << "Signed form: " << signedForm << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testDestructor() {
    std::cout << "\n=== Testing Destructor ===" << std::endl;
    std::cout << "Creating and destroying forms in scope:" << std::endl;
    {
        Form temp1("Temp Form 1", 50, 25);
        Form temp2("Temp Form 2", 75, 100);
        std::cout << "Forms created in scope" << std::endl;
    }
    std::cout << "Forms should be destroyed when leaving scope" << std::endl;
}

int main() {
    std::cout << "=== COMPREHENSIVE FORM CLASS TESTING ===" << std::endl;
    
    testDefaultConstructor();
    testParameterizedConstructor();
    testCopyConstructor();
    testAssignmentOperator();
    testGetters();
    testBeSigned();
    testExceptions();
    testStreamOperator();
    testDestructor();
    
    return 0;
}