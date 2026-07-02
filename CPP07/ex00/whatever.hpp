/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:59:17 by oztozdem          #+#    #+#             */
/*   Updated: 2025/11/26 12:11:53 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void swap(T& x, T& y) {
	T tmp;

	tmp = x;
	x = y;
	y = tmp;
}

template<typename T>
T min(T& x, T& y) {
	return (x < y ? x : y);
}

template<typename T>
T max(T& x, T& y) {
	return (x > y ? x : y);
}