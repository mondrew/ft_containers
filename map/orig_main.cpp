/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:25:56 by mondrew           #+#    #+#             */
/*   Updated: 2021/02/03 15:57:32 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <map>
#include <iostream>

bool	fncomp(char lhs, char rhs)
{
	return (lhs < rhs);
}

struct	classcomp {

	bool operator()(const char& lhs, const char& rhs) const {

		return (lhs < rhs);
	}
};

void	std_test1(void)
{
	// Constructors
	// Default constructor
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Constructors test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "Default constructor:";
	std::cout << "\033[0m\t\t" << std::endl;

	std::map<char, int>				first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	std::cout << "Print 'first' map elements using indexes:" << std::endl;
	std::cout << "[a]: " << first['a'] << std::endl;
	std::cout << "[b]: " << first['b'] << std::endl;
	std::cout << "[c]: " << first['c'] << std::endl;
	std::cout << "[d]: " << first['d'] << std::endl;

	std::cout << "Print 'first' map elements using iterator:" << std::endl;
	std::map<char, int>::iterator	it = first.begin();
	std::map<char, int>::iterator	ite = first.end();
	while (it != ite)
	{
		std::cout << it->first << ": " << it->second << std::endl;
		it++;
	}

	// Range constructor
	std::cout << "\x1b[33m";
	std::cout << "Range constructor";
	std::cout << "\033[0m\t\t" << std::endl;

	std::map<char, int>				second(first.begin(), first.end());

	std::cout << "Print 'second' map elements using iterator:" << std::endl;
	it = second.begin();
	ite = second.end();
	while (it != ite)
	{
		std::cout << it->first << ": " << it->second << std::endl;
		it++;
	}

	// Copy constructor
	std::cout << "\x1b[33m";
	std::cout << "Copy constructor";
	std::cout << "\033[0m\t\t" << std::endl;

	std::map<char, int>				third(second);

	std::cout << "Print 'third' map elements using iterator:" << std::endl;
	it = third.begin();
	ite = third.end();
	while (it != ite)
	{
		std::cout << it->first << ": " << it->second << std::endl;
		it++;
	}

	// Default constructor with non-default Compare template type (classcomp)
	std::cout << "\x1b[33m";
	std::cout << "Default constructor with non-default Compare template type";
   	std::cout << " (classcomp)";
	std::cout << "\033[0m\t\t" << std::endl;

	std::map<char, int, classcomp>	fourth;

	// Add elements
	fourth['j'] = 42;
	fourth['e'] = 21;
	fourth['d'] = 41;
	fourth['i'] = 22;

	std::cout << "Print 'fourth' map elements using iterator:" << std::endl;
	std::map<char, int, classcomp>::iterator	it1 = fourth.begin();
	std::map<char, int, classcomp>::iterator	ite1 = fourth.end();
	while (it1 != ite1)
	{
		std::cout << it1->first << ": " << it1->second << std::endl;
		it1++;
	}

	// Default constructor with non-default compare function ptr
	std::cout << "\x1b[33m";
	std::cout << "Default constructor with non-default compare function ptr";
	std::cout << "\033[0m\t\t" << std::endl;

	bool(*fn_pt)(char, char) = fncomp;
	std::map<char, int, bool(*)(char, char)>		fistdh(fn_pt); // function pointer as Compare

	std::cout << "Print 'fistdh' map elements using iterator" << std::endl;
	// Add elements
	fistdh['a'] = 1;
	fistdh['n'] = 2;
	fistdh['a'] = 3;
	fistdh['k'] = 4;
	fistdh['i'] = 5;
	fistdh['n'] = 6;

	std::map<char, int, bool(*)(char, char)>::iterator	it2 = fistdh.begin();
	std::map<char, int, bool(*)(char, char)>::iterator	ite2 = fistdh.end();
	while (it2 != ite2)
	{
		std::cout << it2->first << ": " << it2->second << std::endl;
		it2++;
	}

	std::cout << std::endl;
}

void	std_test2(void)
{
	// Iterators
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Iterators test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	std::map<char, int>				first;

	first['p'] = 100;
	first['a'] = 300;
	first['d'] = 500;
	first['m'] = 700;
	first['e'] = 900;

	std::cout << "\x1b[33m";
	std::cout << "Print 'first' map elements using iterator:";
	std::cout << "\033[0m\t\t" << std::endl;
	std::map<char, int>::iterator	it = first.begin();
	std::map<char, int>::iterator	ite = first.end();
	while (it != ite)
	{
		std::cout << it->first << ": " << it->second << std::endl;
		it++;
	}

	std::cout << "\x1b[33m";
	std::cout << "Print 'first' map elements using reverse_iterator:";
	std::cout << "\033[0m\t\t" << std::endl;
	std::map<char, int>::reverse_iterator	rit = first.rbegin();
	std::map<char, int>::reverse_iterator	rite = first.rend();
	while (rit != rite)
	{
		std::cout << rit->first << ": " << rit->second << std::endl;
		rit++;
	}

	std::cout << std::endl;
}

// Capacity
void	std_test3(void)
{
	// Capacity
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Capacity functions test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	std::map<char, int>				mymap;

	mymap['p'] = 100;
	mymap['a'] = 300;
	mymap['d'] = 500;
	mymap['m'] = 700;
	mymap['e'] = 900;

	std::cout << "\x1b[33m";
	std::cout << "Print 'mymap' map elements:";
	std::cout << "\033[0m\t\t" << std::endl;
	std::map<char, int>::iterator	it = mymap.begin();
	std::map<char, int>::iterator	ite = mymap.end();
	while (it != ite)
	{
		std::cout << it->first << ": " << it->second << std::endl;
		it++;
	}

	// Empty function
	std::cout << "\x1b[33m";
	std::cout << "Empty function test";
	std::cout << "\033[0m\t\t" << std::endl;

	if (mymap.empty())
		std::cout << "map 'mymap' is empty" << std::endl;
	else
		std::cout << "map 'mymap' is not empty" << std::endl;

	// Size function
	std::cout << "\x1b[33m";
	std::cout << "Size function test";
	std::cout << "\033[0m\t\t" << std::endl;
	std::cout << "mymap size is: " << mymap.size() << std::endl;

	// Max_size function
	std::cout << "\x1b[33m";
	std::cout << "Max_size function test";
	std::cout << "\033[0m\t\t" << std::endl;
	std::cout << "mymap max_size is: " << mymap.max_size() << std::endl;

	std::cout << std::endl;

	std::cout << "existing element: " << mymap['e'] << std::endl;
	std::cout << "non-existing element: " << mymap['x'] << std::endl;
}

int		main(void)
{
	// Constructors
	std_test1();

	// Iterators
	std_test2();

	// Capacity
	std_test3();

	/*
	std_test4();

	std_test5();

	std_test6();

	std_test7();

	std_test8();

	std_test9();

	std_test10();

	std_test11();

	std_test12();
	*/

	return (0);
}
