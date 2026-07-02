/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:13:47 by oztozdem          #+#    #+#             */
/*   Updated: 2025/11/26 12:12:57 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template<typename T, typename Func>
void iter(T* arr, size_t len, Func f) {
	if (!arr)
		return;
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}