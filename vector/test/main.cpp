/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:14:24 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/17 21:59:55 by mondrew          ###   ########.fr       */
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
		std::vector<int>		vints2;
		std::vector<int>		v2(5, 100);

		vints.push_back(1);
		vints.push_back(2);
		vints.push_back(3);
		vints.push_back(4);
		vints.push_back(5);
		vints.push_back(6);

		vints2.push_back(1);
		vints2.push_back(2);
		vints2.push_back(3);
		vints2.push_back(4);
		vints2.push_back(5);
		vints2.push_back(6);

		//vints2.erase(vints2.end() - 1);

		std::cout << "Equal: " << (vints == vints2) << std::endl;
		std::cout << "Not equal: " << (vints != vints2) << std::endl;
		std::cout << "Less: " << (vints < vints2) << std::endl;
		std::cout << "More: " << (vints > vints2) << std::endl;

		std::cout << "vints len: " << vints.size() << std::endl;
		vints.swap(v2);
		std::cout << "vints len after swap: " << vints.size() << std::endl;

		std::cout << "v2 capacity b4 clear(): " << v2.capacity() << std::endl;
		v2.clear();

		std::cout << "v2 capacity after clear(): " << v2.capacity() << std::endl;

		std::vector<int>::iterator	it = vints.begin();
//		std::vector<int>::iterator	ite = vints.end();

		it = vints.erase(it + 3);

		std::cout << "!!! " << *it << std::endl;

		it = vints.begin();

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
