/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainthana <ainthana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:39:51 by ainthana          #+#    #+#             */
/*   Updated: 2026/03/11 18:30:21 by ainthana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {

	private:
		T				*_data;
		unsigned int	_size;

	public:
		Array() : _data(NULL), _size(0){
			
		}
		
		Array(unsigned int n) : _data(NULL), _size(n) {
			if (n  > 0) {
				_data = new T[n];
				for (unsigned int i = 0; i < n; i++) {
					_data[i] = T();
				}
			}
		}
		
		Array(Array const &copy) : _data(NULL), _size(0) {
			*this = copy;
		}
		
		Array	&operator=(Array const &copy) {
			if (this != &copy) {
				if (_data)
					delete[] _data;
				
				_size = copy._size;

				if (_size > 0) {
					_data = new T[_size];
					for (unsigned int i = 0; i < _size; i++) {
						_data[i] = copy._data[i];
					}
				}
				else {
					_data = NULL;
				}
			}
			
			return *this;
		}

		~Array() {
			if (_data) {
				delete[] _data;
			}
		}

		T		&operator[](unsigned int index) {
			if (index>= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
		}
		
		T const	&operator[](unsigned int index) const {
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
		}

		unsigned int	size() const {
			return _size;
		}
};

#include "Array.hpp"

#endif