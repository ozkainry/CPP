/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:35:42 by oztozdem          #+#    #+#             */
/*   Updated: 2025/08/22 12:42:06 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() {
	this->_total_contacts = 0;
	this->_index = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact() {
	
	Contact	new_contact;

	new_contact.setInfos();
	
	contact[_index] = new_contact;
	_index = (_index + 1) % 8;
	if (_total_contacts < 8)
		_total_contacts++;
		
	std::cout << "Contact added successfully." << std::endl;
	return ;
}

std::string	formatField(const std::string& field) {
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

void	printSearch(std::string a, std::string b, std::string c, std::string d) {
	std::cout << "|";
	std::cout << std::setw(10) << std::right << formatField(a);
	std::cout << "|";
	std::cout << std::setw(10) << std::right << formatField(b);
	std::cout << "|";
	std::cout << std::setw(10) << std::right << formatField(c);
	std::cout << "|";
	std::cout << std::setw(10) << std::right << formatField(d);
	std::cout << "|" << std::endl;
	return ;
}

std::string	intToString(int n) {
	std::stringstream	ss;
	ss << n;
	return (ss.str());
}

void	PhoneBook::searchContacts() const {
	if (_total_contacts == 0) {
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}
	
	printSearch("INDEX", "FIRST NAME", "SURNAME", "NICKNAME");

	for (int i = 0; i < _total_contacts; i++) {
		std::string	first = contact[i].getFirstName();
		std::string	surname = contact[i].getSurname();
		std::string	nickname = contact[i].getNickname();
		printSearch(intToString(i), first, surname, nickname);
	}

	std::string	input;
	std::cout << "Choose an index between 0 and " << _total_contacts - 1 << ": ";
	std::getline(std::cin, input);
	if (std::cin.fail() || std::cin.eof()) {
		std::cout << "Input error" << std::endl;
		return ;
	}

	if (input.length() != 1 || input[0] < '0' || input[0] > '0' + (_total_contacts - 1)) {
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	int	index = input[0] - '0';
	contact[index].display();
	return ;
}