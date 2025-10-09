/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:18:49 by oztozdem          #+#    #+#             */
/*   Updated: 2025/08/22 12:44:20 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact() {}

Contact::~Contact() {}

std::string	trim(const std::string& input) {
	size_t	start = 0;
	while (start < input.length() && std::isspace(input[start]))
		start++;

	size_t	end = input.length();
	while (end > start && std::isspace(input[end - 1]))
		end--;

	return (input.substr(start, end - start));
}

bool	isDigit(const std::string& input) {
	for (int i = 0; input[i]; i++)
		if (std::isdigit((int)input[i]))
			return (true);
	return (false);
}

void	Contact::setInfos() {
	while (1) {
		std::string	first;
		std::cout << "First name: ";
		std::getline(std::cin, first);
		if (std::cin.fail() || std::cin.eof() || first.empty()) {
			std::cout << "Invalid first name." << std::endl;
			continue ;
		}
		first = trim(first);
		if (isDigit(first) == true) {
			std::cout << "Number found in first name." << std::endl;
			continue ;
		}
		this->_first_name = first;
		break ;
	}

	while (1) {
		std::string	surname;
		std::cout << "Surname: ";
		std::getline(std::cin, surname);
		if (std::cin.fail() || std::cin.eof() || surname.empty()) {
			std::cout << "Invalid surname." << std::endl;
			continue ;
		}
		surname = trim(surname);
		if (isDigit(surname) == true) {
			std::cout << "Number found in first name." << std::endl;
			continue ;
		}
		this->_surname = surname;
		break ;
	}
	
	while (1) {
		std::string	nickname;
		std::cout << "Nickname: ";
		std::getline(std::cin, nickname);
		if (std::cin.fail() || std::cin.eof() || nickname.empty()) {
			std::cout << "Invalid nickname." << std::endl;
			continue ;
		}
		this->_nickname = nickname;
		break ;
	}

	while (1) {
		std::string	phone;
		std::cout << "Phone number: ";
		std::getline(std::cin, phone);
		if (std::cin.fail() || std::cin.eof() || phone.empty()) {
			std::cout << "Invalid phone number." << std::endl;
			continue ;
		}
		phone = trim(phone);
		if (isDigit(phone) == false) {
			std::cout << "Phone number must only have digits." << std::endl;
			continue ;
		}
		if (phone.length() != 10) {
			std::cout << "Phone number must have 10 digits." << std::endl;
			continue ;
		}
		this->_phone = phone;
		break ;
	}

	while (1) {
		std::string	secret;
		std::cout << "Secret: ";
		std::getline(std::cin, secret);
		if (std::cin.fail() || std::cin.eof() || secret.empty()) {
			std::cout << "Invalid darkest secret." << std::endl;
			continue ;
		}
		secret = trim(secret);
		this->_secret = secret;
		break ;
	}
}

std::string	Contact::getFirstName() const {
	return (_first_name);
}

std::string	Contact::getSurname() const {
	return (_surname);
}

std::string	Contact::getNickname() const {
	return (_nickname);
}

void	Contact::display() const {
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Surname: " << _surname << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phone << std::endl;
	std::cout << "Darkest secret: " << _secret << std::endl;
}