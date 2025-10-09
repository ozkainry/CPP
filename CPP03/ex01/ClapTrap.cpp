/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:10:19 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/02 13:21:05 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout	<< "Booting up " << _name
				<< "... Ready to cause some chaos!"
				<< std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout	<< "Booting up " << _name
				<< "... Ready to cause some chaos!"
				<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& other) {
	*this = other;
	std::cout	<< _name
				<< " has been cloned. Twice the fun, double the trouble!"
				<< std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout	<< _name
				<< " is shutting down... probably permanently. Goodbye, cruel world!"
				<< std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
		std::cout	<< _name
					<< " is toast! Can't attack..." << std::endl;
		return ;
	}
	if (_energyPoints > 0) {
		std::cout	<< _name << " fires at " << target
					<< ", causing " << _attackDamage
					<< " points of damage ! Pew pew!" << std::endl;
		--_energyPoints;
	}
	else {
		std::cout	<< _name
					<< " is out of juice! No energy points left."
					<< std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
    std::cout << " " << _name << std::endl;
    std::cout << " HP: " << _hitPoints 
              << " | Energy: " << _energyPoints << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout	<< _name
					<< " is already kaput!" << std::endl;
		return ;
	}
	if (amount < _hitPoints) {
		std::cout	<< _name << " takes " << amount
					<< " points of damage! Ouch, that hurts!" << std::endl;
		_hitPoints -= amount;
	}
	else {
		std::cout	<< _name << " takes " << amount
					<< " points of damage and is destroyed! Kaboom!"
					<< std::endl;
		_hitPoints = 0;
	}
	std::cout << "----------------------------------------" << std::endl;
    std::cout << " " << _name << std::endl;
    std::cout << " HP: " << _hitPoints 
              << " | Energy: " << _energyPoints << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints > 0) {
		if (_energyPoints > 0) {
			std::cout	<< _name << " restores " << amount
						<< " hit points! Feeling shiny and ready!" << std::endl;
			--_energyPoints;
			_hitPoints += amount;
		}
		else {
			std::cout	<< _name
						<< " is out of juice! Can't repair." << std::endl;
			return ;
		}
	}
	else {
		std::cout	<< _name
					<< " is toast... can't repair." << std::endl;
		return ;
	}
	std::cout << "----------------------------------------" << std::endl;
    std::cout << " " << _name << ": " << std::endl;
    std::cout << " HP: " << _hitPoints 
              << " | Energy: " << _energyPoints << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}
