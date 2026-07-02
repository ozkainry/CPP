/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:59:22 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/10 15:09:13 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
    std::cout << "=== Bureaucrats creation tests ===" << std::endl;
    
    try {
        Bureaucrat b1("Alice", 50);
        std::cout << b1 << std::endl;
        
        Bureaucrat b2("Bob", 1);
        std::cout << b2 << std::endl;
        
        Bureaucrat b3("Charlie", 150);
        std::cout << b3 << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Invalid grades tests ===" << std::endl;
    
    try {
        Bureaucrat invalid1("TooHigh", 0);
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what();
    }
    
    try {
        Bureaucrat invalid2("TooLow", 151);
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "=== Incrementation & decrementation tests ===" << std::endl;
    
    try {
        Bureaucrat worker("Worker", 75);
        std::cout << "Initial: " << worker << std::endl;
        
        worker.increment();
        std::cout << "After increment: " << worker << std::endl;
        
        worker.decrement();
        std::cout << "After decrement: " << worker << std::endl;
        
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Limits tests ===" << std::endl;
    
    try {
        Bureaucrat topBureaucrat("TopBoss", 1);
        std::cout << topBureaucrat << std::endl;
        topBureaucrat.increment();
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what();
    }
    
    try {
        Bureaucrat bottomBureaucrat("Intern", 150);
        std::cout << bottomBureaucrat << std::endl;
        bottomBureaucrat.decrement();
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "=== Copy constructor tests ===" << std::endl;
    
    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
	
    return 0;
}