/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:45:03 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/24 15:36:32 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AForm;

class Intern {
	private:
		AForm* createShrubbery(std::string const& target);
		AForm* createRobotomy(std::string const& target);
		AForm* createPardon(std::string const& target);
	public:
		Intern();
		Intern(Intern const& other);
		~Intern();
		Intern& operator=(const Intern& other);

		AForm* makeForm(std::string const& formName, std::string const& target);
		class UnknownFormException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Unknown form name\n"; }
		};
};