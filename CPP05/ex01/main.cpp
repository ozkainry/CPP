/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:59:22 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/10 15:11:46 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main(void) {
    std::cout << "=== Form creation ===" << std::endl;
    try {
        Form form("Tax Form", 50, 25);
        std::cout << form << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid form creation ===" << std::endl;
    try {
        Form form("Tax Form", 0, 25);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what();
    }

    try {
        Form form("Tax Form", 50, 151);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
   std::cout << "=== Successful signing ===" << std::endl;
    try {
        Bureaucrat caspar("Caspar", 30);
        Form form("Contract", 50, 25);

        std::cout << caspar << std::endl;
        std::cout << form << std::endl;

        caspar.signForm(form);
        std::cout << form << std::endl;
        caspar.signForm(form);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Failed signing ===" << std::endl;
    try {
        Bureaucrat caspar("Caspar", 60);
        Form form("Contract", 50, 25);

        std::cout << caspar << std::endl;
        std::cout << form << std::endl;

        caspar.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what();
    }

    std::cout << "\n=== Copy constructor ===" << std::endl;
    try {
        Form form("Contract", 50, 25);
        Bureaucrat bureaucrat("Bureaucrat", 30);
        
        bureaucrat.signForm(form);
        Form copy(form);

        std::cout << "Form: " << form << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what();
    }

    return 0;
}