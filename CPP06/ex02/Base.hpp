/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:46:54 by oztozdem          #+#    #+#             */
/*   Updated: 2025/11/04 15:51:52 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base {
	public:
		virtual ~Base() {};
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

class A : public Base {};

class B : public Base {};

class C : public Base {};