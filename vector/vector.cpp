/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:46:57 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/19 20:27:00 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <cstddef>

template < typename T, typename A >
ft::vector<T, A>::vector(void) {

	this->_array = 0;
	this->_size = 0;
	this->_capacity = 0;

	return ;
}

template < typename T, typename A >
ft::vector<T, A>::vector(size_t n, T const &val) {

	size_t	i = 0;

	if (n == 0) // ???
		return ;

	this->_array = new T[n];
	this->_size = n;
	this->_capacity = n;

	while (i < n)
	{
		this->_array[i] = val;
		i++;
	}
}

template < typename T, typename A >
ft::vector<T, A>::vector(ft::vector<T, A>::iterator first, \
											ft::vector<T, A>::iterator last) {
	size_t	i = 0;
	size_t	n = last - first;

	if (n == 0 || last < first) // ???
		return ;

	this->_array = new T[n];
	this->_size = n;
	this->_capacity = n;

	while (i < n)
	{
		this->_array[i] = *first;
		i++;
		first++;
	}
}

template < typename T, typename A >
ft::vector<T, A>::vector(ft::vector<T, A> const &src) {

	*this = src;
}

template < typename T, typename A >
ft::vector<T, A>::~vector(void) {

	delete [] this->_array;

	return ;
}

template < typename T, typename A >
ft::vector<T, A>	&ft::vector<T, A>::operator=(ft::vector<T, A> const &rhs) {

	size_t	i = 0;

	if (rhs.getArray() == 0 || rhs.size() == 0)
	{
		this->_array = 0;
		this->_size = 0;
		this->_capacity = 0;
		return (*this);
	}

	this->_array = new T[rhs.capacity()];
	this->_size = rhs.size();
	this->_capacity = rhs.capacity();

	while (i < this->_size)
	{
		this->_array[i] = rhs.getArray()[i];
		i++;
	}

	return (*this);
}
