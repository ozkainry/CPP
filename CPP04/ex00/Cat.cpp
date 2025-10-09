/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:45:21 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/04 16:17:49 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout	<< "A cat has emerged from the shadows!"
				<< std::endl;
}

Cat::Cat(Cat const& other) : Animal(other) {
	std::cout	<< "A cat has been copied! Twice the mischief!"
				<< std::endl;
}

Cat::~Cat() {
	std::cout	<< "A cat has vanished into the shadows..."
				<< std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

void Cat::makeSound() {
	std::cout << "Meow!" << std::endl;
}
