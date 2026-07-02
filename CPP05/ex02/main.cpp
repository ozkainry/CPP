/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:59:22 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/24 15:32:15 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void) {
    srand(time(NULL));
    
    std::cout << "=== Shrubbery Creation Success ===\n";
    
    try {
        AForm* form = new ShrubberyCreationForm("tree");
        Bureaucrat bureaucrat("Caspar", 1);

        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what();
    }

    std::cout << "\n=== Robotomy Request Success ===" << std::endl;

    try {
        AForm* form = new RobotomyRequestForm("Caspar");
        Bureaucrat bureaucrat("Victor", 1);

        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what();
    }
    
    std::cout << "\n=== Presidential Pardon Success ===" << std::endl;

    try {
        AForm* form = new PresidentialPardonForm("Caspar");
        Bureaucrat bureaucrat("Zaphod", 1);

        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what();
    }

    std::cout << "\n=== Execute, signing failed ===" << std::endl;

    try {
        AForm* form = new PresidentialPardonForm("Caspar");
        Bureaucrat bureaucrat("Brice", 150);

        bureaucrat.executeForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what();
    }

    try {
        AForm* form = new PresidentialPardonForm("Caspar");
        Bureaucrat bureaucrat("Brice", 150);

        bureaucrat.signForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what();
    }

    try {
        AForm* form = new PresidentialPardonForm("Caspar");
        Bureaucrat signer("Victor", 1);
        Bureaucrat bureaucrat("Brice", 150);

        signer.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what();
    }

    return 0;
}