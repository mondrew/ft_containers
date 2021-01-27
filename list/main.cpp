/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:58:32 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/27 12:02:29 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include <list>
#include <iostream>
#include <string>

// DO IT (see test21)

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
	ft::list<int>::iterator		it21 = it2;
	it21++;
	it21++;
	it21++;

	ft::list<int>				v3(it2, it21);
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

void	ft_test6(void)
{
	// Iterators test
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>>>> [ Iterators test (ints) ] <<<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::list<int>				v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);

	std::cout << "\x1B[33m";
	std::cout << "List in direct order using classic iterator:";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<int>::iterator	it2 = v2.begin();
	ft::list<int>::iterator	ite2 = v2.end();

	while (it2 != ite2)
	{
		std::cout << *it2 << " ";
		it2++;
	}
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "List in reverse order using reverse_iterator:";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<int>::reverse_iterator	rit2 = v2.rbegin();
	ft::list<int>::reverse_iterator	rite2 = v2.rend();

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

	std::cout << "\x1B[33m";
	std::cout << "Iterator comparison operators test:";
	std::cout << "\033[0m\t\t" << std::endl;
	if (it2 == ite2)
		std::cout << "it2 is equal to ite2" << std::endl;
	if (it2 != ite2)
		std::cout << "it2 is NOT equal to ite2" << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Reverse iterator comparison operators test:";
	std::cout << "\033[0m\t\t" << std::endl;
	if (rit2 == rite2)
		std::cout << "rit2 is equal to rite2" << std::endl;
	if (rit2 != rite2)
		std::cout << "rit2 is NOT equal to rite2" << std::endl;

	std::cout << std::endl;
}

void	ft_test7(void)
{
	// Capacity
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>> [ Capacity member-functions of list class] <<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::list<std::string>		vs0;

	vs0.push_back("May");
	vs0.push_back("the");
	vs0.push_back("Force");
	vs0.push_back("be");
	vs0.push_back("with");
	vs0.push_back("you!");

	ft::list<std::string>::iterator	it = vs0.begin();
	ft::list<std::string>::iterator	ite = vs0.end();

	std::cout << "\x1B[33m";
	std::cout << "Initial list content:";
	std::cout << "\033[0m\t\t" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "list size(): " << vs0.size() << std::endl;
	std::cout << "list max_size(): " << vs0.max_size() << std::endl;
	std::cout << std::endl;

	// Resize to 10
	std::cout << "\x1B[33m";
	std::cout << "Resize list to 10 with \"!\" values";
	std::cout << "\033[0m\t\t" << std::endl;
	vs0.resize(10, "!");
	std::cout << "list size(): " << vs0.size() << std::endl;
	it = vs0.begin();
	ite = vs0.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << std::endl;

	// Resize to 12 by default
	std::cout << "\x1B[33m";
	std::cout << "Resize list to 12 by default values";
	std::cout << "\033[0m\t\t" << std::endl;
	vs0.resize(12);
	std::cout << "list size(): " << vs0.size() << std::endl;
	it = vs0.begin();
	ite = vs0.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << std::endl;

	// Resize to 5 by default
	std::cout << "\x1B[33m";
	std::cout << "Resize list to 5 by default values";
	std::cout << "\033[0m\t\t" << std::endl;
	vs0.resize(5);
	std::cout << "list size(): " << vs0.size() << std::endl;
	it = vs0.begin();
	ite = vs0.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << std::endl;

	// Resize to 3 with "!"
	std::cout << "\x1B[33m";
	std::cout << "Resize list to 3 with \"!\" value";
	std::cout << "\033[0m\t\t" << std::endl;
	vs0.resize(3, "!");
	std::cout << "list size(): " << vs0.size() << std::endl;
	it = vs0.begin();
	ite = vs0.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << std::endl;

	if (vs0.empty())
		std::cout << "The list is empty" << std::endl;
	else
		std::cout << "The list is not empty" << std::endl;
	std::cout << std::endl;
}

void	ft_test8(void)
{
	// Element access
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>>>> [ Element access test ] <<<<<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<double>		vd0;

	vd0.push_back(12.021);
	vd0.push_back(42.0);
	vd0.push_back(42.042042);
	vd0.push_back(2.1);
	vd0.push_back(21.42);

	ft::list<double>::iterator	it = vd0.begin();
	ft::list<double>::iterator	ite = vd0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Using 'front' and 'back' member-function:";
	std::cout << "\033[0m\t\t" << std::endl;
	std::cout << "front: " << vd0.front() << " | end: " << vd0.back() << std::endl;

	std::cout << std::endl;
}

void	ft_test9(void)
{
	// Modifiers: push_front & push_back & pop_front & pop_back
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: push_back & pop_back";
	std::cout << " & push_front & pop_front ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<int>		v0;

	std::cout << "\x1B[33m";
	std::cout << "Using 'push_front' & 'push_back' member-functions:";
	std::cout << "\033[0m\t\t" << std::endl;
	v0.push_front(2);
	v0.push_front(1);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);

	ft::list<int>::iterator	it = v0.begin();
	ft::list<int>::iterator	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Using 'pop_back' 2 times & 'pop_front 1 time:";
	std::cout << "\033[0m\t\t" << std::endl;
	v0.pop_back();
	v0.pop_back();
	v0.pop_front();

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
	ft::list<int>		v0;
	ft::list<int>		v1;

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

	ft::list<int>::iterator	it = v0.begin();
	ft::list<int>::iterator	ite = v0.end();

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

	ft::list<int>::iterator	it_tmp = it;
	it_tmp++;
	it_tmp++;
	it_tmp++;
	it_tmp++;
	it_tmp++;
	v1.assign(it, it_tmp);

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

	std::cout << "v1 size: " << v1.size() << std::endl;

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
	ft::list<int>		v0;

	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);

	ft::list<int>::iterator	it = v0.begin();
	ft::list<int>::iterator	ite = v0.end();

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

	std::cout << "v0 size: " << v0.size() << std::endl;
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
	ft::list<int>		v0;

	v0.push_back(1);
	v0.push_back(2);
	v0.push_back(3);
	v0.push_back(4);
	v0.push_back(5);

	ft::list<int>::iterator	it = v0.begin();
	ft::list<int>::iterator	ite = v0.end();

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

	it++;
	it++;
	it++;
	v0.insert(it, 42);
	it = v0.begin();
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	it = v0.begin();

	std::cout << "v0 size: " << v0.size() << std::endl;

	std::cout << std::endl;
}

void	ft_test13(void)
{
	// Insert (fill)
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: insert (fill) ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<int>		v0;

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

	ft::list<int>::iterator	it = v0.begin();
	ft::list<int>::iterator	ite = v0.end();

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

	it++;
	it++;
	it++;
	v0.insert(it, 5, 42);

	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "v0 size: " << v0.size() << std::endl;

	std::cout << std::endl;
}

void	ft_test14(void)
{
	// Insert (range)
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: insert (range) ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<int>		v0;
	ft::list<int>		v1(10, 42);

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

	ft::list<int>::iterator	it = v0.begin();
	ft::list<int>::iterator	ite = v0.end();

	ft::list<int>::iterator	it1 = v1.begin();
	ft::list<int>::iterator	ite1 = v1.end();

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

	std::cout << "v1 size: " << v1.size() << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Insert elements on 3 position:";
	std::cout << "\033[0m\t\t" << std::endl;

	it1++;
	it1++;
	it1++;

	it++;
	it++;
	it++;
	it++;
	it++;
	v1.insert(it1, it, ite);
	it = v0.begin();

	it1 = v1.begin();
	ite1 = v1.end();

	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;

	std::cout << "v1 size: " << v1.size() << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Insert elements on 2 position:";
	std::cout << "\033[0m\t\t" << std::endl;

	it1 = v1.begin();
	ite1 = v1.end();

	it1++;
	it1++;
	it1++;
	it1++;
	it1++;
	it1++;
	it1++;

	v1.insert(it1, it, ite);

	it1 = v1.begin();
	ite1 = v1.end();

	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;

	std::cout << "v1 size: " << v1.size() << std::endl;

	std::cout << std::endl;
}

void	ft_test15(void)
{
	// Erase (single)
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: erase (single) ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<int>		v0;

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

	ft::list<int>::iterator	it = v0.begin();
	ft::list<int>::iterator	ite = v0.end();

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

	it++;
	it++;
	it++;
	it++;
	it++;
	v0.erase(it);

	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "v0 size: " << v0.size() << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Erase element at the last position";
	std::cout << "\033[0m\t\t" << std::endl;

	ite--;
	v0.erase(ite);

	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "v0 size: " << v0.size() << std::endl;
	std::cout << std::endl;
}

void	ft_test16(void)
{
	// Erase (range)
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: erase (range) ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<int>		v0;

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

	ft::list<int>::iterator	it = v0.begin();
	ft::list<int>::iterator	ite = v0.end();

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

	it++;
	ft::list<int>::iterator	it1 = it;
	it1++;
	it1++;
	it1++;
	v0.erase(it, it1);

	it = v0.begin();
	ite = v0.end();

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "v0 size: " << v0.size() << std::endl;

	std::cout << "\x1B[33m";
	std::cout << "Erase element with same iterators";
	std::cout << "\033[0m\t\t" << std::endl;

	it = v0.begin();

	it++;
	ft::list<int>::iterator	ret = v0.erase(it, it);
	std::cout << "ret: " << *ret << std::endl;

	std::cout << std::endl;
}

void	ft_test17(void)
{
	// Swap
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: swap ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<int>		v0;
	ft::list<int>		v1(11, 42);

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

	ft::list<int>::iterator	it = v0.begin();
	ft::list<int>::iterator	ite = v0.end();

	ft::list<int>::iterator	it1 = v1.begin();
	ft::list<int>::iterator	ite1 = v1.end();

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

	std::cout << "v1 size: " << v1.size() << std::endl;

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

	std::cout << "v1 size: " << v1.size() << std::endl;

	std::cout << std::endl;
}

void	ft_test18(void)
{
	// Clear
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Modifiers test: clear ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<int>		v1(10, 42);

	ft::list<int>::iterator	it1 = v1.begin();
	ft::list<int>::iterator	ite1 = v1.end();

	std::cout << "Initial array:" << std::endl;
	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;
	it1 = v1.begin();

	std::cout << "v1 size: " << v1.size() << std::endl;

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

	std::cout << "v1 size: " << v1.size() << std::endl;

	std::cout << std::endl;
}

void	ft_test19(void)
{
	// Non-member functions
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Non-member functions ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<int>		v0(5, 21);
	ft::list<int>		v1(10, 42);
	ft::list<int>		v2(v1);

	ft::list<int>::iterator	it = v0.begin();
	ft::list<int>::iterator	ite = v0.end();

	ft::list<int>::iterator	it1 = v1.begin();
	ft::list<int>::iterator	ite1 = v1.end();

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

	std::cout << std::endl;
}

void	ft_test20(void)
{
	// Splice
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Splice functions test ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::list<int>				mylist1, mylist2;
	ft::list<int>::iterator		it;
	ft::list<int>::iterator		tmp;

	// Set some initial values
	for (int i = 1; i <= 4; ++i) 	// mylist1: 1 2 3 4
		mylist1.push_back(i);

	for (int i = 1; i <= 3; ++i)
		mylist2.push_back(i * 10);	// mylist2: 10 20 30

	// Print initial lists
	std::cout << "\x1b[33m";
	std::cout << "Initial mylist1 list: ";
	std::cout << "\033[0m\t\t" << std::endl;

	it = mylist1.begin();
	while (it != mylist1.end())
	{
		std::cout << *it << ' ';
		it++;
	}
	std::cout << std::endl;
	std::cout << "mylist1 size: " << mylist1.size() << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "Initial mylist2 list: ";
	std::cout << "\033[0m\t\t" << std::endl;
	it = mylist2.begin();
	while (it != mylist2.end())
	{
		std::cout << *it << ' ';
		it++;
	}
	std::cout << std::endl;
	std::cout << "mylist2 size: " << mylist2.size() << std::endl;

	it = mylist1.begin();
	++it;							// points to 2


	std::cout << "\x1b[32m";
	std::cout << "SPLICE (entire list) mylist2 to mylist1 at the 1st position:";
	std::cout << "\033[0m\t\t" << std::endl;
	mylist1.splice(it, mylist2);	// mylist1: 1 10 20 30 2 3 4
									// mylist2 (empty)
									// 'it' still points to 2 (the 5th element)
	// Print lists after splicing
	std::cout << "\x1b[33m";
	std::cout << "'it' still points to: ";
	std::cout << "\033[0m\t\t" << std::endl;
	std::cout << *it << std::endl;

	tmp = it; // Save it
	std::cout << "\x1b[33m";
	std::cout << "mylist1 after splicing mylist2 to it at 1st position:";
	std::cout << "\033[0m\t\t" << std::endl;

	it = mylist1.begin();
	while (it != mylist1.end())
	{
		std::cout << *it << ' ';
		it++;
	}
	std::cout << std::endl;
	std::cout << "mylist1 size: " << mylist1.size() << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "mylist2 after being spliced to mylist1 at 1st position:";
	std::cout << "\033[0m\t\t" << std::endl;
	it = mylist2.begin();
	while (it != mylist2.end())
	{
		std::cout << *it << ' ';
		it++;
	}
	std::cout << std::endl;
	std::cout << "mylist2 size: " << mylist2.size() << std::endl;

	it = tmp; // Recover it

	std::cout << "\x1b[32m";
	std::cout << "SPLICE (single) mylist2 to mylist1 at the 1st position:";
	std::cout << "\033[0m\t\t" << std::endl;
	mylist2.splice(mylist2.begin(), mylist1, it);
									// mylist1: 1 10 20 30 3 4
									// mylist2: 2
									// 'it' is now invalid.
	// Print lists after splicing
	std::cout << "\x1b[33m";
	std::cout << "'it' is invalid now"; // TEST in ORIGINAL!!!
	std::cout << "\033[0m\t\t" << std::endl;
	std::cout << *it << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "mylist1 after splicing";
	std::cout << "\033[0m\t\t" << std::endl;

	it = mylist1.begin();
	while (it != mylist1.end())
	{
		std::cout << *it << ' ';
		it++;
	}
	std::cout << std::endl;
	std::cout << "mylist1 size: " << mylist1.size() << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "mylist2 after splicing";
	std::cout << "\033[0m\t\t" << std::endl;
	it = mylist2.begin();
	while (it != mylist2.end())
	{
		std::cout << *it << ' ';
		it++;
	}
	std::cout << std::endl;
	std::cout << "mylist2 size: " << mylist2.size() << std::endl;

	it = mylist1.begin();
	it++;
	it++;
	it++;							// 'it' points now to 30
	std::cout << "IT: " << *it << std::endl; // test

	std::cout << "\x1b[32m";
	std::cout << "SPLICE (elem range) mylist1 3 last elements to the begining:";
	std::cout << "\033[0m\t\t" << std::endl;
	mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
									// mylist1: 30 3 4 1 10 20
	
	std::cout << "mylist1 contains:";
	for (it = mylist1.begin(); it != mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "mylist2 contains:";
	for (it = mylist2.begin(); it != mylist2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << std::endl;
}

void	ft_test21(void)
{
	// Remove
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Remove functions test ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	//int				myints[] = {17, 89, 7, 14};
	//ft::list<int>	mylist(myints, myints + 4); // DO IT
	ft::list<int>	mylist;

	mylist.push_back(17);
	mylist.push_back(89);
	mylist.push_back(7);
	mylist.push_back(14);

	std::cout << "\x1b[33m";
	std::cout << "Initial list:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << std::endl;

	mylist.remove(89);

	std::cout << "\x1b[33m";
	std::cout << "List after removing element '89':";
	std::cout << "\033[0m\t\t" << std::endl;
	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << std::endl;
}

// a predicate implemented as a function:
bool single_digit (const int &value) { return (value < 10); }

// a predicate implemented as a class:
struct is_odd {
bool operator() (const int &value) { return (value % 2) == 1; }
};

void	ft_test22(void)
{
	// Remove_if
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Remove_if functions test ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	//int myints[]= {15,36,7,17,20,39,4,1};
	//std::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1
	ft::list<int>	mylist;

	mylist.push_back(15);
	mylist.push_back(36);
	mylist.push_back(7);
	mylist.push_back(17);
	mylist.push_back(20);
	mylist.push_back(39);
	mylist.push_back(4);
	mylist.push_back(1);

	std::cout << "\x1b[33m";
	std::cout << "Initial list:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << std::endl;

	mylist.remove_if(single_digit);           // 15 36 17 20 39

	mylist.remove_if(is_odd());               // 36 20

	std::cout << "\x1b[33m";
	std::cout << "List after remove_if:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << std::endl;
}

// a binary predicate implemented as a function:
bool	same_integral_part(double first, double second)
{ return (int(first) == int(second)); }

// a binary predicate implemented as a class:
struct is_near {
	bool	operator() (double first, double second)
	{ return (fabs(first - second) < 5.0); }
};


void	ft_test23(void)
{
	// Unique
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Unique functions test ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	//double				mydoubles[] = {12.15, 2.72, 73.0, 12.77, 3.14, \
	//									12.77, 73.35, 72.25, 15.3, 72.25};
	double				mydoubles[] = {2.72, 3.14, 12.15, 12.77, 12.77,
										15.3, 72.25, 72.25, 73.0, 73.35};
	ft::list<double>	mylist(mydoubles, mydoubles + 10);

	std::cout << "\x1b[33m";
	std::cout << "Initial list:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (ft::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << std::endl;
	    
	//mylist.sort();			// 2.72, 3.14, 12.15, 12.77, 12.77,
							// 15.3, 72.25, 72.25, 73.0, 73.35
	mylist.unique();		// 2.72, 3.14, 12.15, 12.77
							// 15.3, 72.25, 73.0,  73.35
	mylist.unique(same_integral_part);		// 2.72, 3.14, 12.15
											// 15.3, 72.25, 73.0
	mylist.unique(is_near());				// 2.72, 12.15, 72.25

	std::cout << "\x1b[33m";
	std::cout << "List after unique function:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (ft::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << std::endl;
}

bool	mycomparison(double first, double second)
{
	return (int(first) < int(second));
}

void	ft_test24(void)
{
	// Merge
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Merge functions test ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::list<double>	first, second;

	first.push_back(2.2);
	first.push_back(2.9);
	first.push_back(3.1);

	second.push_back(1.4);
	second.push_back(3.7);
	second.push_back(7.1);

	std::cout << "\x1b[33m";
	std::cout << "Initial 'first' list";
	std::cout << "\033[0m\t\t" << std::endl;
	for (ft::list<double>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "Initial 'second' list";
	std::cout << "\033[0m\t\t" << std::endl;
	for (ft::list<double>::iterator it = second.begin(); it!=second.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	first.merge(second);

	std::cout << "\x1b[33m";
	std::cout << "List 'first' after merge function:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (ft::list<double>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "List 'second' after merge function:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (ft::list<double>::iterator it = second.begin(); it!=second.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "Added 2.1 to the 'second' list";
   	std::cout << " and merge it to 'first' with pointer to comparison function";
	std::cout << "\033[0m\t\t" << std::endl;
	for (ft::list<double>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	second.push_back(2.1);

	first.merge(second, mycomparison);

	std::cout << "\x1b[33m";
	std::cout << "List 'first' after merge (comp) function:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (ft::list<double>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << std::endl;
}

bool	compare_nocase(const std::string &first, const std::string &second)
{
	unsigned int	i = 0;
	while ((i < first.length()) && (i < second.length()))
	{
		if (tolower(first[i]) < tolower(second[i]))
			return (true);
		else if (tolower(first[i]) > tolower(second[i]))
			return (false);
		++i;
	}
	return (first.length() < second.length());
}

void	ft_test25(void)
{
	// Sort
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Sort functions test ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::list<std::string>				mylist;
	ft::list<std::string>::iterator		it;

	mylist.push_back("one");
	mylist.push_back("two");
	mylist.push_back("Three");

	std::cout << "\x1b[33m";
	std::cout << "Initial list:";
	std::cout << "\033[0m\t\t" << std::endl;
	for(it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << std::endl;

	// Sort
	mylist.sort();

	std::cout << "\x1b[33m";
	std::cout << "List after sort:";
	std::cout << "\033[0m\t\t" << std::endl;
	for(it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << std::endl;

	// Sort with comparison function ptr
	mylist.sort(compare_nocase);

	std::cout << "\x1b[33m";
	std::cout << "List after sort with comparison function:";
	std::cout << "\033[0m\t\t" << std::endl;
	for(it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << std::endl;
}

void	ft_test26(void)
{
	// Reverse
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>> [ Reverse functions test ] <<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::list<int>				mylist;
	ft::list<int>::iterator	it;

	for (int i = 1; i < 10; ++i)
		mylist.push_back(i);

	std::cout << "\x1b[33m";
	std::cout << "Initial list:";
	std::cout << "\033[0m\t\t" << std::endl;
	for(it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << std::endl;

	// Reverse list
	mylist.reverse();

	std::cout << "\x1b[33m";
	std::cout << "Inverted list:";
	std::cout << "\033[0m\t\t" << std::endl;
	for(it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << *it << ' ';
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

	// Iterators test
	ft_test6();

	// Capacity
	ft_test7();

	// Element access
	ft_test8();

	// Modifiers: push_front & push_back & pop_front & pop_back
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

	// Operations
	// Splice
	ft_test20();

	// Remove
	ft_test21();

	// Remove if
	ft_test22();

	// Unique
	ft_test23();

	// Merge
	ft_test24();

	// Sort
	ft_test25();

	// Reverse
	ft_test26();
	return (0);
}
