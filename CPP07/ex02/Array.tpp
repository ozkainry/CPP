/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:29:58 by oztozdem          #+#    #+#             */
/*   Updated: 2025/11/27 11:42:22 by oztozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <stdexcept>
#include <stdio.h>

template<typename T>
Array<T>::Array() {
	_array = NULL;
	_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n) {
	_array = new T[n];
	_size = n;
}

template<typename T>
Array<T>::Array(const Array<T>& other) {
	_size = other._size;
	_array = new T[other._size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		delete[] _array;
		_size = other._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return *this;
}

template<typename T>
Array<T>::~Array() {
	if (_array)
		delete[] _array;
}

template<typename T>
T& Array<T>::operator[](unsigned int idx) {
	if (idx >= _size)
		throw std::out_of_range("Array index out of bounds");
	return _array[idx];
}

template<typename T>
unsigned int Array<T>::size() {
	return _size;
}