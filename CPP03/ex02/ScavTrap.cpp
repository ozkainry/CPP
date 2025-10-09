/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:32:04 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/06 14:59:05 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(), _gateMode(false) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout	<< _name
				<< " is online. Time to guard the gates!"
				<< std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _gateMode(false) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout	<< _name
				<< " is online. Time to guard the gates!"
				<< std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& other) : ClapTrap(other), _gateMode(false) {
	*this = other;
	std::cout	<< _name
				<< " cloned successfully. Twice the paranoia!"
				<< std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout	<< _name << " has been scrapped into spare parts."
				<< std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void ScavTrap::guardGate() {
	if (_hitPoints <= 0) {
		std::cout	<< _name 
					<< " is scrap metal! No way it's gatekeeping..."
					<< std::endl;
		return ;
	}
	if (_gateMode == false) {
		std::cout	<< _name << " has entered Gate Keeper mode! Nobody passes!"
					<< std::endl;
		_gateMode = true;
	}
	else {
		std::cout	<< _name << " is already in Gate Keeper mode!"
					<< std::endl;
	}
}

void ScavTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
		std::cout	<< _name
					<< " is scrap metal! No way it's attacking..." << std::endl;
		return ;
	}
	if (_energyPoints > 0) {
		std::cout	<< _name << " unloads on " << target
					<< ", dealing " << _attackDamage
					<< " damage! Boom! Headshot!" << std::endl;
		--_energyPoints;
	}
	else {
		std::cout	<< _name
					<< " clicks... but nothing happens. Out of ammo—err, energy!"
					<< std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
    std::cout << " " << _name << std::endl;
    std::cout << " HP: " << _hitPoints 
              << " | Energy: " << _energyPoints << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}