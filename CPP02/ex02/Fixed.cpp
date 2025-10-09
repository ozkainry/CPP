/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:21:19 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/05 15:08:07 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _n(0) {}
Fixed::Fixed(const int n) : _n(n << _bits) {}
Fixed::Fixed(const float n) : _n(roundf(n * (1 << _bits))) {}

Fixed::Fixed(Fixed const& other) {
	*this = other;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->_n = other._n;
	return *this;
}

int Fixed::getRawBits(void) const {
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

bool Fixed::operator>(const Fixed& other) const {
	return _n > other._n;
}

bool Fixed::operator<(const Fixed& other) const {
	return _n < other._n;
}

bool Fixed::operator>=(const Fixed& other) const {
	return _n >= other._n;
}

bool Fixed::operator<=(const Fixed& other) const {
	return _n <= other._n;
}

bool Fixed::operator==(const Fixed& other) const {
	return _n == other._n;
}

bool Fixed::operator!=(const Fixed& other) const {
	return _n != other._n;
}

Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
	_n++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	_n++;
	return tmp;
}

Fixed& Fixed::operator--() {
	_n--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	_n--;
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return a > b ? a : b;
}