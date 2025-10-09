/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:47:57 by oztozdem          #+#    #+#             */
/*   Updated: 2025/08/22 13:48:34 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB() {
	this->_name = "Unnamed";
	this->_weapon = NULL;
}

HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& type) {
	this->_weapon = &type;
}

void	HumanB::attack() {
	if (_weapon != NULL)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << "No weapon to attack" << std::endl;
}