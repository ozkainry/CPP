/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:42:24 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/08 11:32:58 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() : _type("Unknown") {}
	
AMateria::AMateria(std::string const& type) : _type(type) {}

AMateria::AMateria(AMateria const& other) {
	*this = other;
}
	
AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}
			
std::string const & AMateria::getType() const {
	return this->_type;
}
	
void AMateria::use(ICharacter& target) {
	std::cout << "* uses materia on " << target.getName() << " *" << std::endl;
}