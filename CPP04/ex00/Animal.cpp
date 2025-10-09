/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:45:21 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/04 16:17:23 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Unknown") {
	std::cout	<< "An unknown animal is born!"
				<< std::endl;
}

Animal::Animal(std::string animal) : type(animal) {
	std::cout	<< "A " << type << " animal is born!"
				<< std::endl;
}

Animal::Animal(Animal const& other) {
	*this = other;
	std::cout	<< "An animal has been duplicated!"
				<< std::endl;
}

Animal::~Animal() {
	std::cout	<< "The " << type
				<< " left the world..."
				<< std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() {
	std::cout << "* Generic animal noised *" << std::endl;
}
