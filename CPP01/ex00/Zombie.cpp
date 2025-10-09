/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:25:06 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/01 11:25:01 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
	this->_name = "Unnamed";
}

Zombie::Zombie(std::string name) {
	this->_name = name;
};

Zombie::~Zombie() {
	std::cout << this->_name << " died." << std::endl;
};

void	Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}