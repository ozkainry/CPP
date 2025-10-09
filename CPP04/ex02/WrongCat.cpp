/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 11:22:41 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/04 16:21:50 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("Cat") {
	std::cout	<< "A wrong cat has spawned... but it meows wrong."
				<< std::endl;
}

WrongCat::WrongCat(WrongCat const& other) : WrongAnimal(other) {
	std::cout	<< "A new wrong cat has been copied... twice the wrong meows!"
				<< std::endl;
}

WrongCat::~WrongCat() {
	std::cout	<< "A wrong cat tried to meow... but failed forever."
				<< std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

void WrongCat::makeSound() {
	std::cout << "Wrong Meow!" << std::endl;
}