/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:19:18 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/10 16:55:05 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}


std::string ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::executeAction() const {
	std::string outfile_name = getTarget() + "_shrubbery";

	std::ofstream outfile(outfile_name.c_str());
	if (!outfile.is_open())
		throw FileOpenException();
	
	outfile << "    oxoxoo    ooxoo\n"
            << "  ooxoxo oo  oxoxooo\n"
            << " oooo xxoxoo ooo ooox\n"
            << " oxo o oxoxo  xoxxoxo\n"
            << "  oxo xooxoooo o ooo\n"
            << "    ooo\\oo\\  /o/o\n"
            << "        \\  \\/ /\n"
            << "         |   /\n"
            << "         |  |\n"
            << "         | D|\n"
            << "         |  |\n"
            << "         |  |\n"
            << "  ______/____\\____\n";

	outfile.close();
}
