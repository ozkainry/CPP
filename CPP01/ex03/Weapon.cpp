/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:07:55 by oztozdem          #+#    #+#             */
/*   Updated: 2025/07/29 12:04:54 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
	this->_type = "Undefined";
}

Weapon::Weapon(const std::string& type) {
	this->_type = type;
}

Weapon::~Weapon() {}

const std::string&	Weapon::getType() {
	return _type;
}

void	Weapon::setType(std::string type) {
	this->_type = type;
}