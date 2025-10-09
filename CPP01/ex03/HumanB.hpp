/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:48:21 by oztozdem          #+#    #+#             */
/*   Updated: 2025/08/22 13:48:31 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon*	_weapon;
	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(Weapon& type);
		void	attack();
};
