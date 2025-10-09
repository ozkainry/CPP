/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:02:42 by oztozdem          #+#    #+#             */
/*   Updated: 2025/08/22 13:56:12 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void	Harl::debug(void) {
	std::cout	<< "[ DEBUG ]\nI love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
				<< "I really do!"
				<< std::endl;
}

void	Harl::info(void) {
	std::cout	<< "[ INFO ]\nI cannot believe adding extra bacon "
				<< "costs more money.\nYou didn't put enough bacon in my burger!"
				<< "\nIf you did, I wouldn't be asking for more!"
				<< std::endl;
}

void	Harl::warning(void) {
	std::cout	<< "[ WARNING ]\nI think I deserve to have some extra bacon for"
				<< " free.\nI've been coming for years, whereas you started "
				<< "working here just last month."
				<< std::endl;
}

void	Harl::error(void) {
	std::cout	<< "[ ERROR ]\nThis is unacceptable! I want to speak to the "
				<< "manager now."
				<< std::endl;
}

void	Harl::complain(std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			(this->*functions[i])();
}