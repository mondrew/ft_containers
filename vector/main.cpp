/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:40:18 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/21 00:59:37 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <cstddef>

void	ft_test1(void)
{
	// Default constructor
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Default constructor test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>				v0;

	std::cout << "Empty vector size: " << v0.size() << std::endl;
	std::cout << std::endl;
}

void	ft_test2(void)
{
	// Fill constructor + iterators + begin() + end()
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>>>>>> [ Fill constructor ] <<<<<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>				v1(5, 100);
	ft::vector<int>::iterator	it1 = v1.begin();
	ft::vector<int>::iterator	ite1 = v1.end();

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
	// Range constructor + reverse_iterator + rbegin() + rend()
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>>>>>> [ Range constructor ] <<<<<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>				v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);

	ft::vector<int>::iterator	it2 = v2.begin();

	ft::vector<int>				v3(it2, it2 + 3); // why are they equal?
	ft::vector<int>::iterator	it3 = v3.begin();
	ft::vector<int>::iterator	ite3 = v3.end();

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
	ft::vector<float>				vf0(10, 42.021f);
	ft::vector<float>				vf1(vf0);
	ft::vector<float>::iterator		it4 = vf1.begin();
	ft::vector<float>::iterator		ite4 = vf1.end();

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
	ft::vector<char>				vc0 = ft::vector<char>(5, 'S');
	ft::vector<char>::iterator		it5 = vc0.begin();
	ft::vector<char>::iterator		ite5 = vc0.end();

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

void	ft_test6(void)
{
	// Iterators test
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>>>> [ Iterators test (ints) ] <<<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::vector<int>				v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);

	std::cout << "\x1B[33m";
	std::cout << "Vector in direct order using classic iterator:";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>::iterator	it2 = v2.begin();
	ft::vector<int>::iterator	ite2 = v2.end();

	while (it2 != ite2)
	{
		std::cout << *it2 << " ";
		it2++;
	}
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Vector in reverse order using reverse_iterator:";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>::reverse_iterator	rit2 = v2.rbegin();
	ft::vector<int>::reverse_iterator	rite2 = v2.rend();

	while (rit2 != rite2)
	{
		std::cout << *rit2 << " ";
		rit2++;
	}
	std::cout << std::endl;

	// Iterator
	std::cout << "\x1B[33m";
	std::cout << "Iterator arithmetic operations test:";
	std::cout << "\033[0m\t\t" << std::endl;
	it2 = v2.begin();
	std::cout << "Initail it2: " << *it2 << std::endl;
	it2++;
	std::cout << "After it2++: " << *it2 << std::endl;
	it2--;
	std::cout << "After it2--: " << *it2 << std::endl;
	++it2;
	std::cout << "After ++it2: " << *it2 << std::endl;
	--it2;
	std::cout << "After --it2: " << *it2 << std::endl;
	it2 = it2 + 3;
	std::cout << "it2 = it2 + 3: " << *it2 << std::endl;
	it2 = it2 - 3;
	std::cout << "it2 = it2 - 3: " << *it2 << std::endl;
	it2 += 2;
	std::cout << "it2 += 2: " << *it2 << std::endl;
	it2 -= 2;
	std::cout << "it2 -= 2: " << *it2 << std::endl;
	std::cout << "it2[3]: " << it2[3] << std::endl;

	// Reverse iterator
	std::cout << "\x1B[33m";
	std::cout << "Reverse iterator arithmetic operations test:";
	std::cout << "\033[0m\t\t" << std::endl;
	rit2 = v2.rbegin();
	std::cout << "Initail rit2: " << *rit2 << std::endl;
	rit2++;
	std::cout << "After rit2++: " << *rit2 << std::endl;
	rit2--;
	std::cout << "After rit2--: " << *rit2 << std::endl;
	++rit2;
	std::cout << "After ++rit2: " << *rit2 << std::endl;
	--rit2;
	std::cout << "After --rit2: " << *rit2 << std::endl;
	rit2 = rit2 + 3;
	std::cout << "rit2 = rit2 + 3: " << *rit2 << std::endl;
	rit2 = rit2 - 3;
	std::cout << "rit2 = rit2 - 3: " << *rit2 << std::endl;
	rit2 += 2;
	std::cout << "rit2 += 2: " << *rit2 << std::endl;
	rit2 -= 2;
	std::cout << "rit2 -= 2: " << *rit2 << std::endl;
	std::cout << "rit2[3]: " << rit2[3] << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Iterator comparison operators test:";
	std::cout << "\033[0m\t\t" << std::endl;
	if (it2 == ite2)
		std::cout << "it2 is equal to ite2" << std::endl;
	if (it2 < ite2)
		std::cout << "it2 is less than ite2" << std::endl;
	if (it2 > ite2)
		std::cout << "it2 is greater than ite2" << std::endl;
	if (it2 <= ite2)
		std::cout << "it2 is less than or equal to ite2" << std::endl;
	if (it2 >= ite2)
		std::cout << "it2 is more than or equal to ite2" << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Reverse iterator comparison operators test:";
	std::cout << "\033[0m\t\t" << std::endl;
	if (rit2 == rite2)
		std::cout << "rit2 is equal to rite2" << std::endl;
	if (rit2 < rite2)
		std::cout << "rit2 is less than rite2" << std::endl;
	if (rit2 > rite2)
		std::cout << "rit2 is greater than rite2" << std::endl;
	if (rit2 <= rite2)
		std::cout << "rit2 is less than or equal to rite2" << std::endl;
	if (rit2 >= rite2)
		std::cout << "rit2 is more than or equal to rite2" << std::endl;

	std::cout << std::endl;
}

void	ft_test7(void)
{
	// Capacity
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>> [ Capacity member-functions of vector class] <<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::vector<std::string>		vs0;

	vs0.push_back("May");
	vs0.push_back("the");
	vs0.push_back("Force");
	vs0.push_back("be");
	vs0.push_back("with");
	vs0.push_back("you!");

	ft::vector<std::string>::iterator	it = vs0.begin();
	ft::vector<std::string>::iterator	ite = vs0.end();

	std::cout << "\x1B[33m";
	std::cout << "Initial vector content:";
	std::cout << "\033[0m\t\t" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "vector size(): " << vs0.size();
	std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	std::cout << "vector max_size(): " << vs0.max_size() << std::endl;
	std::cout << std::endl;

	// Resize to 10
	std::cout << "\x1B[33m";
	std::cout << "Resize vector to 10 with \"!\" values";
	std::cout << "\033[0m\t\t" << std::endl;
	vs0.resize(10, "!");
	std::cout << "vector size(): " << vs0.size();
	std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	it = vs0.begin();
	ite = vs0.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	// Resize to 12 by default
	std::cout << "\x1B[33m";
	std::cout << "Resize vector to 12 by default values";
	std::cout << "\033[0m\t\t" << std::endl;
	vs0.resize(12);
	std::cout << "vector size(): " << vs0.size();
	std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	it = vs0.begin();
	ite = vs0.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	// Resize to 5 by default
	std::cout << "\x1B[33m";
	std::cout << "Resize vector to 5 by default values";
	std::cout << "\033[0m\t\t" << std::endl;
	vs0.resize(5);
	std::cout << "vector size(): " << vs0.size();
	std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	it = vs0.begin();
	ite = vs0.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	// Resize to 3 with "!"
	std::cout << "\x1B[33m";
	std::cout << "Resize vector to 3 with \"!\" value";
	std::cout << "\033[0m\t\t" << std::endl;
	vs0.resize(3, "!");
	std::cout << "vector size(): " << vs0.size();
	std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	it = vs0.begin();
	ite = vs0.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	// Reserve 50
	std::cout << "\x1B[33m";
	std::cout << "Reserve 50 for vector";
	std::cout << "\033[0m\t\t" << std::endl;
	vs0.reserve(50);
	std::cout << "vector size(): " << vs0.size();
	std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	it = vs0.begin();
	ite = vs0.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	if (vs0.empty())
		std::cout << "The vector is empty" << std::endl;
	std::cout << std::endl;
}

int		main(void)
{
	/*
	std::vector<std::string>	vs0;

	vs0.push_back("May");
	vs0.push_back("the");
	vs0.push_back("Force");
	vs0.push_back("be");
	vs0.push_back("with");
	vs0.push_back("you!");

	std::vector<std::string>::iterator	it = vs0.begin();
	std::vector<std::string>::iterator	ite = vs0.end();

	std::cout << "Initial vector content:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "vector size(): " << vs0.size() << "cap: " << vs0.capacity() << std::endl;
	std::cout << "vector max_size(): " << vs0.max_size() << std::endl;

	// Resize to 10
	std::cout << "\x1B[33m";
	std::cout << "Resize vector to 10 with \"!\" values";
	std::cout << "\033[0m\t\t" << std::endl;
	vs0.resize(10, "!");
	std::cout << "vector size(): " << vs0.size();
	std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	it = vs0.begin();
	ite = vs0.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	// Resize to 12 by default
	std::cout << "\x1B[33m";
	std::cout << "Resize vector to 12 by default values";
	std::cout << "\033[0m\t\t" << std::endl;
	vs0.resize(12);
	std::cout << "vector size(): " << vs0.size();
	std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	it = vs0.begin();
	ite = vs0.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	// Resize to 5 by default
	std::cout << "\x1B[33m";
	std::cout << "Resize vector to 5 by default values";
	std::cout << "\033[0m\t\t" << std::endl;
	vs0.resize(5);
	std::cout << "vector size(): " << vs0.size();
	std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	it = vs0.begin();
	ite = vs0.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	std::cout << "\x1B[33m";
	std::cout << "Resize vector to 3 with \"!\" value";
	std::cout << "\033[0m\t\t" << std::endl;
	vs0.resize(3, "!");
	std::cout << "vector size(): " << vs0.size();
	std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	it = vs0.begin();
	ite = vs0.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	// Reserve 50
	std::cout << "\x1B[33m";
	std::cout << "Reserve 50 for vector";
	std::cout << "\033[0m\t\t" << std::endl;
	vs0.reserve(50);
	std::cout << "vector size(): " << vs0.size();
	std::cout << ", vector capacity(): " << vs0.capacity() << std::endl;
	it = vs0.begin();
	ite = vs0.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	*/

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

	// Iterators test
	ft_test6();

	// Capacity
	ft_test7();

	return (0);
}
