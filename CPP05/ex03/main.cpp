/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:59:22 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/24 18:41:15 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void) {
    srand(time(NULL));
    
    std::cout << "=== Shrubbery Creation Success ===" << std::endl;
    
    try {
        Intern intern;
        AForm* form = intern.makeForm("shrubbery creation", "garden");
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
        Intern intern;
        AForm* form = intern.makeForm("robotomy request", "Caspar");
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
        Intern intern;
        AForm* form = intern.makeForm("presidential pardon", "Caspar");
        Bureaucrat bureaucrat("Zaphod", 1);

        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what();
    }

    std::cout << "\n=== Failed tests ===" << std::endl;

    try {
        Intern intern;
        AForm* form = intern.makeForm("inexistant form", "inexistant");
        
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what();
    }

    try {
        Intern intern;
        AForm* form = intern.makeForm("PRESIDENTIAL PARDON", "Caspar");
        
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what();
    }

    try {
        Intern intern;
        AForm* form = intern.makeForm("", "Caspar");
        
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what();
    }

    try {
        Intern intern;
        AForm* form = intern.makeForm("presidential pardon", "Caspar");
        Bureaucrat bureaucrat("Brice", 150);

        bureaucrat.signForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what();
    }

    try {
        Intern intern;
        AForm* form = intern.makeForm("presidential pardon", "Caspar");
        Bureaucrat bureaucrat("Brice", 150);
        Bureaucrat signer("Caspar", 1);

        signer.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what();
    }
    
    try {
        Intern intern;
        AForm* form = intern.makeForm("presidential pardon", "Brice");
        Bureaucrat bureaucrat("Caspar", 1);

        bureaucrat.executeForm(*form);
        delete form;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what();
    }

    return 0;
}