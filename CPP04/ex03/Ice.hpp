/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:34:53 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/08 13:03:35 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(Ice const& other);
		virtual ~Ice();
		Ice& operator=(const Ice& other);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};