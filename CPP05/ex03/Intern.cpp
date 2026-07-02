/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:46:16 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/16 11:25:36 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(Intern const& other) {
	(void)other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

AForm* Intern::createShrubbery(std::string const& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string const& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(std::string const& target) {
	return new PresidentialPardonForm(target);	
}

AForm* Intern::makeForm(std::string const& formName, std::string const& target) {
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*creators[3])(std::string const&) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPardon	
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*creators[i])(target);
		}
	}
	
	throw UnknownFormException();
}