/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:58:24 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/23 14:13:58 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>

int		main(void)
{
	std::vector<int>					v0(0, 100);
	std::vector<int>::reverse_iterator	it2 = v0.rbegin();
	std::vector<int>::reverse_iterator	ite2 = v0.rend();

	if (it2 < ite2)
		std::cout << "less" << std::endl;
	else
		std::cout << "more" << std::endl;

	std::vector<int>	v1(it2, it2);

	std::list<int>		lst;

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);

	std::list<int>::iterator		it = lst.begin();
	std::list<int>::iterator		it11;

	std::cout << "One" << std::endl;
	int	*ptr = NULL;
	int a = *ptr;
	std::cout << "Two" << std::endl;
	a = 2;
	//std::list<int>::iterator		ite = lst.end();

	std::list<int>				lst1(it, it);

	std::cout << "lst1 size: " << lst1.size() << std::endl;

	std::list<int>::iterator		it1 = lst1.begin();
	std::list<int>::iterator		ite1 = lst1.end();

	while (it1 != ite1)
	{
		std::cout << *it1 << " ";
		it1++;
	}
	std::cout << std::endl;


	/*
	lst.push_back('a');
	lst.push_back('b');
	lst.push_back('c');
	lst.push_back('d');
	lst.push_back('e');
	*/
}
