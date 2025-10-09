/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:24:32 by oztozdem          #+#    #+#             */
/*   Updated: 2025/08/22 13:48:10 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon&	_weapon;
	public:
		HumanA(std::string name, Weapon& type);
		~HumanA();
		void	attack();
};