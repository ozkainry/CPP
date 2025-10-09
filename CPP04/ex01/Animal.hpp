/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:45:19 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/04 14:01:26 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string name);
		Animal(Animal const& other);
		virtual ~Animal();
		Animal& operator=(const Animal& other);

		virtual void makeSound();
		std::string getType() const;
};