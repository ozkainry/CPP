/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:45:19 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/04 15:21:30 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* brain;
	public:
		Dog();
		Dog(Dog const& other);
		virtual ~Dog();
		Dog& operator=(const Dog& other);

		virtual void makeSound();
		Brain* getBrain();
};