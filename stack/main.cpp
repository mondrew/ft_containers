#include "stack.hpp"
#include <stack>
#include <vector>
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

	ft::stack<int>						first;
	ft::stack<int>						second(mydeque);
	ft::stack<int, std::vector<int> >	third;
	ft::stack<int, std::vector<int> >	fourth(myvector);

	std::cout << "Size of the 'first' stack: " << first.size() << std::endl;
	std::cout << "Size of the 'second' stack: " << second.size() << std::endl;
	std::cout << "Size of the 'third' stack: " << third.size() << std::endl;
	std::cout << "Size of the 'fourth' stack: " << fourth.size() << std::endl;

	std::cout << std::endl;
}

void	ft_test2(void)
{
	// Empty
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Empty function test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::stack<int>	mystack;
	int				sum(0);

	for(int i = 1; i <= 10; i++)
		mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
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

	ft::stack<int>	myints;

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
	// Top
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Top function test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::stack<int>	mystack;

	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	std::cout << "mystack.top() is now: " << mystack.top() << std::endl;
	std::cout << std::endl;
}

void	ft_test5(void)
{
	// Push & pop
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Push & pop function test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::stack<int>	mystack;

	for (int i = 0; i < 5; i++)
		mystack.push(i);

	std::cout << "Popping out elements... ";
	while (!mystack.empty())
	{
		std::cout << mystack.top() << ' ';
		mystack.pop();
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

	// Top
	ft_test4();

	// Push & pop
	ft_test5();

	return (0);
}
