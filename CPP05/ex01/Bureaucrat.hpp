/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:59:32 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/24 15:35:03 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>
#include <iostream>

class Form;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
		
	public:
		Bureaucrat();
		Bureaucrat(std::string const& name, int grade);
		Bureaucrat(Bureaucrat const& other);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& other);

		const std::string& getName() const;
		const int& getGrade() const;
		void increment();
		void decrement();
		void signForm(Form& form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too high\n"; }
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too low\n"; }
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);