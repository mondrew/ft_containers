/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:25:56 by mondrew           #+#    #+#             */
/*   Updated: 2021/02/01 23:40:49 by mondrew          ###   ########.fr       */
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
	std::map<char, int>				first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	std::map<char, int>				second(first.begin(), first.end());
	std::map<char, int>				third(second);

	std::map<char, int, classcomp>	fourth;

	bool	(*fn_pt)(char, char) = fncomp;
	std::map<char, int, bool(*)(char, char)>		fifth(fn_pt); // function pointer as Compare
}

int		main(void)
{
	// Constructors
	ft_test1();

	/*
	ft_test2();

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
