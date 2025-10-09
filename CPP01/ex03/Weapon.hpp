/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:05:44 by oztozdem          #+#    #+#             */
/*   Updated: 2025/08/22 13:48:55 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon {
	private:
		std::string	_type;

	public:
		Weapon();
		Weapon(const std::string& type);
		~Weapon();
		const std::string&	getType();
		void		setType(std::string type);
};