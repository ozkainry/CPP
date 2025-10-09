/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:08:24 by oztozdem          #+#    #+#             */
/*   Updated: 2025/09/08 13:11:07 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria* _materias[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const& other);
		virtual ~MateriaSource();
		MateriaSource& operator=(const MateriaSource& other);

        virtual void learnMateria(AMateria* m);
        virtual AMateria* createMateria(std::string const& type);
};