/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:22:46 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/04 16:20:55 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("Unknown") {
	std::cout	<< "An unknown wrong animal has appeared... something feels off."
				<< std::endl;
}

WrongAnimal::WrongAnimal(std::string animal) : type(animal) {
	std::cout	<< "A " << type << " wrong animal has appeared... something feels off."
				<< std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& other) {
	*this = other;
	std::cout	<< "A new wrong " << type
				<< " is born!"
				<< std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout	<< "The wrong " << type
				<< " has been dissmissed from existence..."
				<< std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() {
	std::cout << "* Generic animal noised *" << std::endl;
}
