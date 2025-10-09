/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:21:19 by oztozdem          #+#    #+#             */
/*   Updated: 2025/08/22 17:23:41 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _n(0) {
	std::cout	<< "Default constructor called"
				<< std::endl;
}

Fixed::Fixed(Fixed const& other) {
	std::cout	<< "Copy constructor called"
				<< std::endl;

	*this = other;
}

Fixed::~Fixed() {
	std::cout	<< "Destructor called"
				<< std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		std::cout	<< "Copy assignment operator called"
					<< std::endl;
		this->_n = other.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout	<< "getRawBits member function called"
				<< std::endl;
				
	return this->_n;
}

void Fixed::setRawBits(int const raw) {
	this->_n = raw;
}