/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:04:42 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/10 16:16:18 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Unknown"), _signed(false), _signGrade(42), _executeGrade(42) {}

Form::Form(std::string const& name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(Form const& other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

Form::~Form() {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}

std::string Form::getName() const {
	return _name;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecuteGrade() const {
	return _executeGrade;
}

bool Form::isSigned() const {
	return _signed;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (_signGrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	if (_signed == true)
		throw FormAlreadySignedException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os	<< "Form " << form.getName()
		<< ", signed: " << (form.isSigned() ? "yes" : "no")
		<< ", sign grade: " << form.getSignGrade()
		<< ", execute grade: " << form.getExecuteGrade();
	return os;
}