/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:04:45 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/24 15:38:38 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _executeGrade;
		
	public:
		Form();
		Form(std::string const& name, int signGrade, int executeGrade);
		Form(Form const& other);
		~Form();
		Form& operator=(const Form& other);

		std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool isSigned() const;
		void beSigned(Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too high\n"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too low\n"; }
		};
		class FormAlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Form is already signed\n"; }
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);