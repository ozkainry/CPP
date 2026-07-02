/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:04:42 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/13 11:48:34 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Unknown"), _signed(false), _signGrade(42), _executeGrade(42) {}

AForm::AForm(std::string const& name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const& other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}

std::string AForm::getName() const {
	return _name;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecuteGrade() const {
	return _executeGrade;
}

bool AForm::isSigned() const {
	return _signed;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (_signGrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	if (_signed == true)
		throw FormAlreadySignedException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os	<< "Form " << form.getName()
		<< ", signed: " << (form.isSigned() ? "yes" : "no")
		<< ", sign grade: " << form.getSignGrade()
		<< ", execute grade: " << form.getExecuteGrade();
	return os;
}

void AForm::execute(Bureaucrat const& bureaucrat) const {
	if (_signed == false)
		throw FormNotSignedException();
	if (_executeGrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	executeAction();
}