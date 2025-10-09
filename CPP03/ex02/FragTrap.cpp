/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:18:02 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/02 15:31:43 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout	<< _name
				<< " has spawned! Who’s up for some high-fives?"
				<< std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout	<< _name
				<< " has spawned! Who’s up for some high-fives?"
				<< std::endl;
}

FragTrap::FragTrap(FragTrap const& other) : ClapTrap(other) {
	*this = other;
	std::cout	<< _name
				<< " cloned successfully. Double the smiles, double the high-fives!"
				<< std::endl;
}

FragTrap::~FragTrap() {
	std::cout	<< _name
				<< " explodes in a shower of confetti... High-five forever!"
				<< std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void FragTrap::highFivesGuys(void) {
	if (_hitPoints > 0) {
		std::cout	<< _name
					<< " raises its hand enthusiastically: 'HIGH-FIVE TIME GUYS!'"
					<< std::endl;
	}
	else {
		std::cout	<< _name 
					<< " is in pieces... no high-fives this time." 
					<< std::endl;
	}
}