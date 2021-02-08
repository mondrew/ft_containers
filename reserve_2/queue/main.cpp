/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 23:17:57 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/27 23:54:32 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.hpp"
#include <queue>
#include <list>
#include <deque>
#include <iostream>

void	ft_test1(void)
{
	// Default constructor
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Default constructor test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	std::deque<int>						mydeque(3, 100);
	std::vector<int>					myvector(2, 200);

	ft::queue<int>						first;
	ft::queue<int>						second(mydeque);
	ft::queue<int, std::vector<int> >	third;
	ft::queue<int, std::vector<int> >	fourth(myvector);

	std::cout << "Size of the 'first' queue: " << first.size() << std::endl;
	std::cout << "Size of the 'second' queue: " << second.size() << std::endl;
	std::cout << "Size of the 'third' queue: " << third.size() << std::endl;
	std::cout << "Size of the 'fourth' queue: " << fourth.size() << std::endl;

	std::cout << std::endl;
}

void	ft_test2(void)
{
	// Empty
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Empty function test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::queue<int>	myqueue;
	int				sum(0);

	for(int i = 1; i <= 10; i++)
		myqueue.push(i);

	while (!myqueue.empty())
	{
		sum += myqueue.front();
		myqueue.pop();
	}

	std::cout << "Total: " << sum << std::endl;

	std::cout << std::endl;
}

void	ft_test3(void)
{
	// Size
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Size function test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::queue<int>	myints;

	std::cout << "0. size: " << myints.size() << std::endl;

	for (int i = 0; i < 5; i++)
		myints.push(i);
	std::cout << "1. size: " << myints.size() << std::endl;

	myints.pop();
	std::cout << "2. size: " << myints.size() << std::endl;

	std::cout << std::endl;
}

void	ft_test4(void)
{
	// Front
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Front function test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::queue<int>	myqueue;

	myqueue.push(77);
	myqueue.push(16);

	myqueue.front() -= myqueue.back();

	std::cout << "myqueue.front() is now: " << myqueue.front() << std::endl;
	std::cout << std::endl;
}

void	ft_test5(void)
{
	// Back
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Back function test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::queue<int>	myqueue;

	myqueue.push(12);
	myqueue.push(75);

	myqueue.back() -= myqueue.front();

	std::cout << "myqueue.back() is now: " << myqueue.back() << std::endl;
	std::cout << std::endl;
}

void	ft_test6(void)
{
	// Push & pop
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Push & pop function test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::queue<int>	myqueue;
	int				myint;

	std::cout << "Please enter some integers (enter 0 to end):\n";

	do {
		std::cin >> myint;
		myqueue.push(myint);
	} while (myint);

	std::cout << "My queue contains: ";
	while (!myqueue.empty())
	{
		std::cout << myqueue.front() << ' ';
		myqueue.pop();
	}

	std::cout << std::endl;
}

int		main(void)
{
	// Default constructor
	ft_test1();

	// Empty
	ft_test2();

	// Size
	ft_test3();

	// Front
	ft_test4();

	// Back
	ft_test5();

	// Push & pop
	ft_test6();

	return (0);
}
