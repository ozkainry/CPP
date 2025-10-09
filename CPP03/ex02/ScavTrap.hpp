/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:32:01 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/02 15:18:16 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		bool	_gateMode;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const& other);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap& other);

		void guardGate();
		void attack(const std::string& target);
};