/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:25:56 by mondrew           #+#    #+#             */
/*   Updated: 2021/02/03 12:23:57 by mondrew          ###   ########.fr       */
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
	ft::map<char, int>				first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	std::cout << "[a]: " << first['a'] << std::endl;
	std::cout << "[b]: " << first['b'] << std::endl;
	std::cout << "[c]: " << first['c'] << std::endl;
	std::cout << "[d]: " << first['d'] << std::endl;

	ft::map<char, int>::iterator	it = first.begin();
	ft::map<char, int>::iterator	ite = first.end();

	std::cout << it->first << ": " << it->second << std::endl;
	std::cout << it->right->first << ": " << it->right->second << std::endl;

	std::cout << "--------------------------------------------------" << std::endl;
	it = first.begin();// test

	while (it != ite)
	{
		std::cout << it->first << ": " << it->second << std::endl;
		it++;
	}
	std::cout << "--------------------------------------------------" << std::endl;


	ft::map<char, int>				second(first.begin(), first.end());
	ft::map<char, int>				third(second);

	ft::map<char, int, classcomp>	fourth;

	bool	(*fn_pt)(char, char) = fncomp;
	ft::map<char, int, bool(*)(char, char)>		fifth(fn_pt); // function pointer as Compare
}

/*
void	ft_test2(void)
{
	// Constructors
	std::map<char, int>				first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	std::map<char, int>::iterator	it = first.begin();
	std::map<char, int>::iterator	ite = first.end();

	while (it != ite)
	{
		std::cout << it->first << ": " << it->second << std::endl;
		it++;
	}
	std::cout << "--------------------------------------------------" << std::endl;

	it = first.begin();
	it--;
	std::cout << it->first << ": " << it->second << std::endl;

	std::cout << "--------------------------------------------------" << std::endl;


	std::map<char, int>				second(first.begin(), first.end());
	std::map<char, int>				third(second);

	std::map<char, int, classcomp>	fourth;

	bool	(*fn_pt)(char, char) = fncomp;
	std::map<char, int, bool(*)(char, char)>		fifth(fn_pt); // function pointer as Compare
}
*/

int		main(void)
{
	// Constructors
	ft_test1();

	//ft_test2();
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
