/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:58:32 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/25 23:03:00 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <iostream>

void	ft_test1(void)
{
	// Default constructor
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Default constructor test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<int>	v0;

	std::cout << "Empty list size: " << v0.size() << std::endl;
	std::cout << std::endl;
}

void	ft_test2(void)
{
	// Fill constructor + iterators + begin() + end()
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>>>>>> [ Fill constructor ] <<<<<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<int>				v1(5, 100);
	ft::list<int>::iterator	it1 = v1.begin();
	ft::list<int>::iterator	ite1 = v1.end();

	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void	ft_test3(void)
{
	// Range constructor
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>>>>>> [ Range constructor ] <<<<<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<int>				v2;

	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);

	ft::list<int>::iterator		it2 = v2.begin();

	ft::list<int>				v3(it2, it2 + 3);
	ft::list<int>::iterator		it3 = v3.begin();
	ft::list<int>::iterator		ite3 = v3.end();

	while (it3 != ite3)
	{
		std::cout << *it3 << " ";
		it3++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void	ft_test4(void)
{
	// Copy constructor
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>> [ Copy constructor test (floats) ] <<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::list<float>				vf0(10, 42.021f);
	ft::list<float>				vf1(vf0);

	ft::list<float>::iterator	it4 = vf1.begin();
	ft::list<float>::iterator	ite4 = vf1.end();

	while (it4 != ite4)
	{
		std::cout << *it4 << " ";
		it4++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void	ft_test5(void)
{
	// Assignment operation overload
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>> [ Assignment operation test (chars) ] <<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<char>				vc0 = ft::list<char>(5, 'S');
	ft::list<char>::iterator	it5 = vc0.begin();
	ft::list<char>::iterator	ite5 = vc0.end();

	it5++;
	it5--;

	--ite5;
	++ite5;

	while (it5 != ite5)
	{
		std::cout << *it5 << " ";
		it5++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

int		main(void)
{
	// Default constructor
	ft_test1();

	// Fill constructor
	ft_test2();

	// Range constructor
	ft_test3();

	// Copy constructor
	ft_test4();

	// Assignment operation
	ft_test5();

	return (0);
}
