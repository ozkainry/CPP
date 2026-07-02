/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:19:21 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/13 11:34:01 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
	private:
		const std::string _target;

	protected:
		virtual void executeAction() const;
		
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const& target);
		PresidentialPardonForm(PresidentialPardonForm const& other);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		std::string getTarget() const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);