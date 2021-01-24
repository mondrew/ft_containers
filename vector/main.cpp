/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:40:18 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/25 02:21:37 by mondrew          ###   ########.fr       */
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

void	ft_test8(void)
{
	// Element access
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>>>> [ Element access test ] <<<<<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<double>		vd0;
	int						i = 0;

	vd0.push_back(12.021);
	vd0.push_back(42.0);
	vd0.push_back(42.042042);
	vd0.push_back(2.1);
	vd0.push_back(21.42);

	vd0[0] = 33;

	std::cout << "\x1B[33m";
	std::cout << "Using index operator:";
	std::cout << "\033[0m\t\t" << std::endl;
	int						n = vd0.size();

	while (i < n)
	{
		std::cout << vd0[i] << " ";
		i++;
	}
	std::cout <<std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Using 'at' member-function for 3rd element:";
	std::cout << "\033[0m\t\t" << std::endl;
	std::cout << vd0.at(3) << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Using 'front' and 'back' member-function:";
	std::cout << "\033[0m\t\t" << std::endl;
	std::cout << "front: " << vd0.front() << " | end: " << vd0.back() << std::endl;

	std::cout << std::endl;
}

void	ft_test9(void)
{
	// Modifiers: push_back & pop_back
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: push_back & pop_back ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>		v0;

	std::cout << "\x1B[33m";
	std::cout << "Using 'push_back' member-function:";
	std::cout << "\033[0m\t\t" << std::endl;
	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);

	ft::vector<int>::iterator	it = v0.begin();
	ft::vector<int>::iterator	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Using 'pop_back' member-function 2 times:";
	std::cout << "\033[0m\t\t" << std::endl;
	v0.pop_back();
	v0.pop_back();

	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << std::endl;
}

void	ft_test10(void)
{
	// Modifiers: assign range
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: assign range ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>		v0;
	ft::vector<int>		v1;

	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);
	v0.push_back(6);
	v0.push_back(7);
	v0.push_back(8);
	v0.push_back(9);
	v0.push_back(10);

	ft::vector<int>::iterator	it = v0.begin();
	ft::vector<int>::iterator	ite = v0.end();

	std::cout << "Initial array:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();
	ite = v0.end();

	std::cout << "\x1B[33m";
	std::cout << "Using 'assign' range member-function:";
	std::cout << "\033[0m\t\t" << std::endl;

	v1.assign(it, it + 5);

	std::cout << "v1 size: " << v1.size() << std::endl;

	it = v1.begin();
	ite = v1.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Using 'assign' range with equal params member-function:";
	std::cout << "\033[0m\t\t" << std::endl;
	it = v0.begin();
	ite = v0.end();
	v1.assign(it, it);

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;

	it = v1.begin();
	ite = v1.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	ft_test11(void)
{
	// Modifiers: assign fill
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: assign fill ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>		v0;

	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);

	ft::vector<int>::iterator	it = v0.begin();
	ft::vector<int>::iterator	ite = v0.end();

	std::cout << "Initial array:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();
	ite = v0.end();

	std::cout << "\x1B[33m";
	std::cout << "Using 'assign' fill member-function:";
	std::cout << "\033[0m\t\t" << std::endl;

	v0.assign(7, 42);

	std::cout << "v0 size: " << v0.size() << std::endl;

	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Using 'assign' fill member-function with 0:";
	std::cout << "\033[0m\t\t" << std::endl;
	v0.assign(0, 21);

	std::cout << "v0 size: " << v0.size();
   	std::cout << " | v0 capacity: " << v0.capacity() << std::endl;
	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	ft_test12(void)
{
	// Insert (single element)
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: insert (single) ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>		v0;

	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);

	ft::vector<int>::iterator	it = v0.begin();
	ft::vector<int>::iterator	ite = v0.end();

	std::cout << "Initial array:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();

	std::cout << "\x1B[33m";
	std::cout << "Insert 1 element on 3 position:";
	std::cout << "\033[0m\t\t" << std::endl;

	v0.insert(it + 3, 42);
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	it = v0.begin();

	std::cout << "v0 size: " << v0.size();
   	std::cout << " | v0 capacity: " << v0.capacity() << std::endl;

	std::cout << std::endl;
}

void	ft_test13(void)
{
	// Insert (fill)
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: insert (fill) ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>		v0;

	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);
	v0.push_back(6);
	v0.push_back(7);
	v0.push_back(8);
	v0.push_back(9);
	v0.push_back(10);

	ft::vector<int>::iterator	it = v0.begin();
	ft::vector<int>::iterator	ite = v0.end();

	std::cout << "Initial array:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();

	std::cout << "\x1B[33m";
	std::cout << "Insert 5 element on 3 position:";
	std::cout << "\033[0m\t\t" << std::endl;

	v0.insert(it + 3, 5, 42);

	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "v0 size: " << v0.size();
   	std::cout << " | v0 capacity: " << v0.capacity() << std::endl;

	std::cout << std::endl;
}

void	ft_test14(void)
{
	// Insert (range)
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: insert (range) ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>		v0;
	ft::vector<int>		v1(10, 42);

	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);
	v0.push_back(6);
	v0.push_back(7);
	v0.push_back(8);
	v0.push_back(9);
	v0.push_back(10);

	ft::vector<int>::iterator	it = v0.begin();
	ft::vector<int>::iterator	ite = v0.end();

	ft::vector<int>::iterator	it1 = v1.begin();
	ft::vector<int>::iterator	ite1 = v1.end();

	std::cout << "Initial array 1 (src):" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();

	std::cout << "Initial array 2 (dest):" << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;
	it1 = v1.begin();

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Insert elements on 3 position:";
	std::cout << "\033[0m\t\t" << std::endl;

	v1.insert(it1 + 3, it + 5, ite);

	it1 = v1.begin();
	ite1 = v1.end();

	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Insert elements on 2 position:";
	std::cout << "\033[0m\t\t" << std::endl;

	it1 = v1.begin();
	ite1 = v1.end();

	v1.insert(it1 + 7, it, ite);

	it1 = v1.begin();
	ite1 = v1.end();

	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;

	std::cout << std::endl;
}

void	ft_test15(void)
{
	// Erase (single)
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: erase (single) ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>		v0;

	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);
	v0.push_back(6);
	v0.push_back(7);
	v0.push_back(8);
	v0.push_back(9);
	v0.push_back(10);

	ft::vector<int>::iterator	it = v0.begin();
	ft::vector<int>::iterator	ite = v0.end();

	std::cout << "Initial array:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();

	std::cout << "\x1B[33m";
	std::cout << "Erase element at 5th position";
	std::cout << "\033[0m\t\t" << std::endl;

	v0.erase(it + 5);

	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "v0 size: " << v0.size();
   	std::cout << " | v0 capacity: " << v0.capacity() << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Erase element at the last position";
	std::cout << "\033[0m\t\t" << std::endl;

	v0.erase(ite);

	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "v0 size: " << v0.size();
   	std::cout << " | v0 capacity: " << v0.capacity() << std::endl;
	std::cout << std::endl;
}

void	ft_test16(void)
{
	// Erase (range)
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: erase (range) ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>		v0;

	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);
	v0.push_back(6);
	v0.push_back(7);
	v0.push_back(8);
	v0.push_back(9);
	v0.push_back(10);

	ft::vector<int>::iterator	it = v0.begin();
	ft::vector<int>::iterator	ite = v0.end();

	std::cout << "Initial array:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();

	std::cout << "\x1B[33m";
	std::cout << "Erase element from 1 to 4 position";
	std::cout << "\033[0m\t\t" << std::endl;

	v0.erase(it + 1, it + 4);

	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "v0 size: " << v0.size();
   	std::cout << " | v0 capacity: " << v0.capacity() << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Erase element with same iterators";
	std::cout << "\033[0m\t\t" << std::endl;

	it = v0.begin();

	ft::vector<int>::iterator	ret = v0.erase(it + 1, it + 1);
	std::cout << "ret: " << *ret << std::endl;

	std::cout << std::endl;
}

void	ft_test17(void)
{
	// Swap
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: swap ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>		v0;
	ft::vector<int>		v1(10, 42);

	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);
	v0.push_back(6);
	v0.push_back(7);
	v0.push_back(8);
	v0.push_back(9);
	v0.push_back(10);

	ft::vector<int>::iterator	it = v0.begin();
	ft::vector<int>::iterator	ite = v0.end();

	ft::vector<int>::iterator	it1 = v1.begin();
	ft::vector<int>::iterator	ite1 = v1.end();

	std::cout << "Initial array 1:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();

	std::cout << "Initial array 2:" << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;
	it1 = v1.begin();

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Swap:";
	std::cout << "\033[0m\t\t" << std::endl;

	v0.swap(v1);

	it = v0.begin();
	ite = v0.end();

	it1 = v1.begin();
	ite1 = v1.end();

	std::cout << "Array 1 after swap:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();

	std::cout << "Array 2 after swap:" << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;
	it1 = v1.begin();

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;

	std::cout << std::endl;
}

void	ft_test18(void)
{
	// Clear
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: clear ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>		v1(10, 42);

	ft::vector<int>::iterator	it1 = v1.begin();
	ft::vector<int>::iterator	ite1 = v1.end();

	std::cout << "Initial array:" << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;
	it1 = v1.begin();

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Clear:";
	std::cout << "\033[0m\t\t" << std::endl;

	v1.clear();

	it1 = v1.begin();
	ite1 = v1.end();

	std::cout << "Array after clear:" << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;

	std::cout << "v1 size: " << v1.size();
   	std::cout << " | v1 capacity: " << v1.capacity() << std::endl;

	std::cout << std::endl;
}

void	ft_test19(void)
{
	// Non-member functions
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Non-member functions ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::vector<int>		v0(5, 21);
	ft::vector<int>		v1(10, 42);
	ft::vector<int>		v2(v1);

	ft::vector<int>::iterator	it = v0.begin();
	ft::vector<int>::iterator	ite = v0.end();

	ft::vector<int>::iterator	it1 = v1.begin();
	ft::vector<int>::iterator	ite1 = v1.end();

	std::cout << "Initial array 1:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	it = v0.begin();

	std::cout << "Initial array 2:" << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Operator '==':";
	std::cout << "\033[0m\t\t" << std::endl;

	if (v0 == v1)
		std::cout << "v0 is equal to v1" << std::endl;
	else
		std::cout << "v0 is NOT equal to v1" << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Operator '!=':";
	std::cout << "\033[0m\t\t" << std::endl;

	if (v0 != v1)
		std::cout << "v0 is NOT equal to v1" << std::endl;
	else
		std::cout << "v0 is equal to v1" << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Operator '<':";
	std::cout << "\033[0m\t\t" << std::endl;

	if (v0 < v1)
		std::cout << "v0 is less than v1" << std::endl;
	else
		std::cout << "v0 is NOT less than v1" << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Operator '<=':";
	std::cout << "\033[0m\t\t" << std::endl;

	if (v0 <= v1)
		std::cout << "v0 is less than or equal to v1" << std::endl;
	else
		std::cout << "v0 is NOT less than or equal to v1" << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Operator '>':";
	std::cout << "\033[0m\t\t" << std::endl;

	if (v0 > v1)
		std::cout << "v0 is greater than v1" << std::endl;
	else
		std::cout << "v0 is NOT greater than v1" << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "operator '>=':";
	std::cout << "\033[0m\t\t" << std::endl;

	if (v1 >= v2)
		std::cout << "v1 is greater than or equal to v2" << std::endl;
	else
		std::cout << "v1 is NOT greater than or equal to v2" << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "Swap v0 & v1:";
	std::cout << "\033[0m\t\t" << std::endl;

	swap(v0, v1);

	it = v0.begin();
	ite = v0.end();

	it1 = v1.begin();
	ite1 = v1.end();

	std::cout << "Array 1 after swap:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "Array 2 after swap:" << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
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

	// Iterators test
	ft_test6();

	// Capacity
	ft_test7();

	// Element access
	ft_test8();

	// Modifiers: push_back & pop_back
	ft_test9();

	// Modifiers: assign range
	ft_test10();

	// Modifiers: assign fill
	ft_test11();

	// Insert (single element)
	ft_test12();

	// Insert (fill)
	ft_test13();

	// Insert (range)
	ft_test14();

	// Erase (single)
	ft_test15();

	// Erase (range)
	ft_test16();

	// Swap
	ft_test17();

	// Clear
	ft_test18();

	// Non-member functions
	ft_test19();

	return (0);
}
