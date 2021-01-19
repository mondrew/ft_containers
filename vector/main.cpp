/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:40:18 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/19 21:39:32 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <cstddef>

int		main(void)
{
	// Default constructor
	std::cout << "========= [ Default constructor test ] ========" << std::endl;
	ft::vector<int>				v0;

	// Fill constructor + iterators + begin() + end()
	std::cout << "========= [ Fill constructor + iterators";
	std::cout << " + begin() + end() ] ========" << std::endl;
	ft::vector<int>				v1(5, 100);
	ft::vector<int>::iterator	it1 = v1.begin();
	ft::vector<int>::iterator	ite1 = v1.end();

	while (it1 != ite1)
	{
		std::cout << *it1 << " " << std::endl;
		it1++;
	}
	// Range constructor
	std::cout << "========= [ Range constructor + reverse_iterators";
	std::cout << " + rbegin() + rend() ] ========" << std::endl;
	ft::vector<int>				v3;
	v3.push_back(1);
	v3.push_back(2);
	v3.push_back(3);
	v3.push_back(4);
	v3.push_back(5);
	ft::vector<int>				v2(it, it + 2);
	ft::vector<int>::iterator	it2 = v1.begin();
	ft::vector<int>::iterator	ite2 = v1.end();

	while (it2 != ite2)
	{
		std::cout << *it2 << " " << std::endl;
		it2++;
	}

	// Copy constructor


	std::vector<int>			vv0(5, 100);

	std::vector<int>::reverse_iterator	rit = vv0.rbegin();
	std::vector<int>::reverse_iterator	rite = vv0.rend();

	std::cout << "rit: " << *rit << " | rite: " << *rite << std::endl;

	ft::vector<int>				v0;
	ft::vector<int>				v2(5, 100);

	ft::vector<int>::iterator	it2 = v2.begin();
	ft::vector<int>::iterator	ite2 = v2.end();
	ft::vector<int>::iterator	it22 = v2.begin() + 2;

	ft::vector<int>				v1(it2, it22);
	ft::vector<int>::iterator	it = v1.begin();
	ft::vector<int>::iterator	ite = v1.end();

	while (it2 != ite2)
	{
		std::cout << *it2 << " " << std::endl;
		it2++;
		std::cout << "!" << std::endl;
	}

	return (0);
}
