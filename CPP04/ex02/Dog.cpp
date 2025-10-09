/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:45:21 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/04 16:19:31 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	brain = new Brain();
	std::cout	<< "A dog has joined the pack!"
				<< std::endl;
}

Dog::Dog(Dog const& other) : Animal(other) {
	if (other.brain != NULL)
		brain = new Brain(*(other.brain));
	else
		brain = NULL;
	std::cout	<< "A dog has been cloned! Double the barking!"
				<< std::endl;
}

Dog::~Dog() {
	delete brain;
	std::cout	<< "A dog has wagged its tail one last time..."
				<< std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		if (other.brain != NULL)
			brain = new Brain(*(other.brain));
		else
			brain = NULL;
	}
	return *this;
}

void Dog::makeSound() {
	std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() {
	return brain;
}