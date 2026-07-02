/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:19:21 by oztozdem          #+#    #+#             */
/*   Updated: 2025/10/13 11:33:43 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
	private:
		const std::string _target;

	protected:
		virtual void executeAction() const;
		
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const& target);
		RobotomyRequestForm(RobotomyRequestForm const& other);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		std::string getTarget() const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);