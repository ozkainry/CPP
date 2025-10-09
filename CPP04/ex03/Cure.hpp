/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:34:53 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/08 13:03:30 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(Cure const& other);
		virtual ~Cure();
		Cure& operator=(const Cure& other);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};