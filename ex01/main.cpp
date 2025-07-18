/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:22:59 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/18 23:23:29 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== BUREAUCRAT COMPREHENSIVE TESTING ===" << std::endl;
    
    // Test 1: Default Constructor
    std::cout << "\n--- Test 1: Default Constructor ---" << std::endl;
    Bureaucrat defaultBureaucrat;
    std::cout << "Default bureaucrat created: " << defaultBureaucrat << std::endl;
    
    // Test 2: Parameterized Constructor (valid grades)
    std::cout << "\n--- Test 2: Parameterized Constructor (Valid Grades) ---" << std::endl;
    Bureaucrat alice("Alice", 1);      // Highest grade
    Bureaucrat bob("Bob", 75);         // Middle grade
    Bureaucrat charlie("Charlie", 150); // Lowest grade
    
    std::cout << "Highest grade: " << alice << std::endl;
    std::cout << "Middle grade: " << bob << std::endl;
    std::cout << "Lowest grade: " << charlie << std::endl;
    
    // Test 3: Getter Functions
    std::cout << "\n--- Test 3: Getter Functions ---" << std::endl;
    std::cout << "Alice's name: " << alice.getName() << std::endl;
    std::cout << "Alice's grade: " << alice.getGrade() << std::endl;
    std::cout << "Bob's name: " << bob.getName() << std::endl;
    std::cout << "Bob's grade: " << bob.getGrade() << std::endl;
    
    // Test 4: Increment Grade (makes grade better/lower number)
    std::cout << "\n--- Test 4: Increment Grade ---" << std::endl;
    std::cout << "Before increment: " << bob << std::endl;
    bob.incrementGrade(10);
    std::cout << "After increment by 10: " << bob << std::endl;
    bob.incrementGrade(5);
    std::cout << "After increment by 5: " << bob << std::endl;
    
    // Test 5: Decrement Grade (makes grade worse/higher number)
    std::cout << "\n--- Test 5: Decrement Grade ---" << std::endl;
    std::cout << "Before decrement: " << bob << std::endl;
    bob.decrementGrade(20);
    std::cout << "After decrement by 20: " << bob << std::endl;
    bob.decrementGrade(15);
    std::cout << "After decrement by 15: " << bob << std::endl;
    
    // Test 6: Constructor Exception - Grade Too High
    std::cout << "\n--- Test 6: Constructor Exception (Grade Too High) ---" << std::endl;
    try {
        Bureaucrat invalid1("InvalidHigh", 0);
        std::cout << invalid1 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 7: Constructor Exception - Grade Too Low
    std::cout << "\n--- Test 7: Constructor Exception (Grade Too Low) ---" << std::endl;
    try {
        Bureaucrat invalid2("InvalidLow", 151);
        std::cout << invalid2 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 8: Increment Exception - Grade Too High
    std::cout << "\n--- Test 8: Increment Exception (Grade Too High) ---" << std::endl;
    try {
        Bureaucrat topBureaucrat("TopBureaucrat", 1);
        std::cout << "Before increment: " << topBureaucrat << std::endl;
        topBureaucrat.incrementGrade(1);
        std::cout << "After increment: " << topBureaucrat << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 9: Decrement Exception - Grade Too Low
    std::cout << "\n--- Test 9: Decrement Exception (Grade Too Low) ---" << std::endl;
    try {
        Bureaucrat bottomBureaucrat("BottomBureaucrat", 150);
        std::cout << "Before decrement: " << bottomBureaucrat << std::endl;
        bottomBureaucrat.decrementGrade(1);
        std::cout << "After decrement: " << bottomBureaucrat << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 10: Edge Cases - Large increments/decrements
    std::cout << "\n--- Test 10: Edge Cases (Large Changes) ---" << std::endl;
    try {
        Bureaucrat edgeCase("EdgeCase", 75);
        std::cout << "Before large increment: " << edgeCase << std::endl;
        edgeCase.incrementGrade(75);  // Should fail (75 - 75 = 0, which is < 1)
        std::cout << "After large increment: " << edgeCase << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat edgeCase2("EdgeCase2", 75);
        std::cout << "Before large decrement: " << edgeCase2 << std::endl;
        edgeCase2.decrementGrade(76);  // Should fail (75 + 76 = 151, which is > 150)
        std::cout << "After large decrement: " << edgeCase2 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test 11: Insertion Operator Format Test
    std::cout << "\n--- Test 11: Insertion Operator Format ---" << std::endl;
    Bureaucrat formatTest("John Doe", 42);
    std::cout << "Format test: " << formatTest << std::endl;
    std::cout << "Direct output: ";
    std::cout << formatTest;
    
    return 0;
}