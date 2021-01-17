/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:14:24 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/15 23:32:30 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <stdexcept>

int		main(void)
{
	int		n = 5;

	std::cout << n << std::endl;

	try
	{
		std::vector<int>		vints;

		vints.push_back(1);
		vints.push_back(2);
		vints.push_back(3);
		vints.push_back(4);
		vints.push_back(5);
		vints.push_back(6);

		vints.resize(0, 7);

		std::vector<int>::iterator	it = vints.begin();

		for (int i = 0; i < 10; ++i)
		{
			std::cout << &(*it) << " | " << *it << std::endl;
			it++;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}
