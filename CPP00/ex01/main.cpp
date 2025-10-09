/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:18:24 by oztozdem          #+#    #+#             */
/*   Updated: 2025/08/22 12:44:56 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	PhoneBook	book;
	
	(void)argv;
	if (argc == 1) {
		
		std::cout << "=============================================" << std::endl;
		std::cout << "📞  WELCOME TO THE 80s PHONEBOOK INTERFACE  📞" << std::endl;
		std::cout << "=============================================" << std::endl;
		std::cout << "Type one of the following commands:" << std::endl;
		std::cout << "  - ADD    : to add a new contact" << std::endl;
		std::cout << "  - SEARCH : to search and display a contact" << std::endl;
		std::cout << "  - EXIT   : to quit the application" << std::endl;
		
		while (1) {
			std::string	cmd;
			std::cout << "---------------------------------------------" << std::endl;
			std::cout << "> ";
			std::getline(std::cin, cmd);
			if (std::cin.eof() || std::cin.fail()) {
				std::cout << "Input error" << std::endl;
				break ;
			}
			if (cmd == "ADD")
				book.addContact();
			else if (cmd == "SEARCH")
				book.searchContacts();
			else if (cmd == "EXIT")
				break ;
			else
				std::cout << "Command not found" << std::endl;
		}
	}
	return (0);
}
