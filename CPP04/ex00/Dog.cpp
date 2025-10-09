/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:45:21 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/04 16:18:44 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout	<< "A dog has joined the pack!"
				<< std::endl;
}

Dog::Dog(Dog const& other) : Animal(other) {
	std::cout	<< "A dog has been cloned! Double the barking!"
				<< std::endl;
}

Dog::~Dog() {
	std::cout	<< "A dog has wagged its tail one last time..."
				<< std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

void Dog::makeSound() {
	std::cout << "Woof!" << std::endl;
}