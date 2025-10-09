/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:21:19 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/05 14:58:17 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _n(0) {
	std::cout	<< "Default constructor called"
				<< std::endl;
}

Fixed::Fixed(const int n) : _n(n << _bits) {
	std::cout	<< "Int constructor called"
				<< std::endl;
}
Fixed::Fixed(const float n) : _n(roundf(n * (1 << _bits))) {
	std::cout	<< "Float constructor called"
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
		this->_n = other._n;
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

float	Fixed::toFloat(void) const {
	return (float)_n / (1 << _bits);
}

int	Fixed::toInt(void) const {
	return _n >> _bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}