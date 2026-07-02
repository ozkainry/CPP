/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:19:21 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/24 15:35:48 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
	private:
		const std::string _target;

	protected:
		virtual void executeAction() const;
		
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const& target);
		ShrubberyCreationForm(ShrubberyCreationForm const& other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		std::string getTarget() const;

		class FileOpenException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Failed to open file\n"; }
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);