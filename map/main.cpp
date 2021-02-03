/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:25:56 by mondrew           #+#    #+#             */
/*   Updated: 2021/02/03 13:41:20 by mondrew          ###   ########.fr       */
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

void	ft_test1(void)
{
	// Constructors
	// Default constructor
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Constructors test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "Default constructor:";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::map<char, int>				first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	std::cout << "Print 'first' map elements using indexes:" << std::endl;
	std::cout << "[a]: " << first['a'] << std::endl;
	std::cout << "[b]: " << first['b'] << std::endl;
	std::cout << "[c]: " << first['c'] << std::endl;
	std::cout << "[d]: " << first['d'] << std::endl;

	std::cout << "Print 'first' map elements using iterators:" << std::endl;
	ft::map<char, int>::iterator	it = first.begin();
	ft::map<char, int>::iterator	ite = first.end();
	while (it != ite)
	{
		std::cout << it->first << ": " << it->second << std::endl;
		it++;
	}

	// Range constructor
	std::cout << "\x1b[33m";
	std::cout << "Range constructor";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::map<char, int>				second(first.begin(), first.end());

	std::cout << "Print 'second' map elements using iterators:" << std::endl;
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

	ft::map<char, int>				third(second);

	std::cout << "Print 'third' map elements using iterators:" << std::endl;
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

	ft::map<char, int, classcomp>	fourth;

	// Add elements
	fourth['j'] = 42;
	fourth['e'] = 21;
	fourth['d'] = 41;
	fourth['i'] = 22;

	std::cout << "Print 'fourth' map elements using iterators:" << std::endl;
	ft::map<char, int, classcomp>::iterator	it1 = fourth.begin();
	ft::map<char, int, classcomp>::iterator	ite1 = fourth.end();
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
	ft::map<char, int, bool(*)(char, char)>		fifth(fn_pt); // function pointer as Compare

	std::cout << "Print 'fifth' map elements using iterators" << std::endl;
	// Add elements
	fifth['a'] = 1;
	fifth['n'] = 2;
	fifth['a'] = 3;
	fifth['k'] = 4;
	fifth['i'] = 5;
	fifth['n'] = 6;

	ft::map<char, int, bool(*)(char, char)>::iterator	it2 = fifth.begin();
	ft::map<char, int, bool(*)(char, char)>::iterator	ite2 = fifth.end();
	while (it2 != ite2)
	{
		std::cout << it2->first << ": " << it2->second << std::endl;
		it2++;
	}
}

void	ft_test2(void)
{
}

int		main(void)
{
	// Constructors
	ft_test1();

	ft_test2();

	/*
	ft_test3();

	ft_test4();

	ft_test5();

	ft_test6();

	ft_test7();

	ft_test8();

	ft_test9();

	ft_test10();

	ft_test11();

	ft_test12();
	*/

	return (0);
}
