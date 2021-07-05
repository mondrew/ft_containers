#include "map.hpp"
#include <map>
#include <iostream>
#include <utility>

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

	std::cout << "Print 'first' map elements using iterator:" << std::endl;
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

	ft::map<char, int>				third(second);

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

	ft::map<char, int, classcomp>	fourth;

	// Add elements
	fourth['j'] = 42;
	fourth['e'] = 21;
	fourth['d'] = 41;
	fourth['i'] = 22;

	std::cout << "Print 'fourth' map elements using iterator:" << std::endl;
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

	std::cout << "Print 'fifth' map elements using iterator" << std::endl;
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

	std::cout << std::endl;
}

void	ft_test2(void)
{
	// Iterators
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Iterators test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::map<char, int>				first;

	first['p'] = 100;
	first['a'] = 300;
	first['d'] = 500;
	first['m'] = 700;
	first['e'] = 900;

	std::cout << "\x1b[33m";
	std::cout << "Print 'first' map elements using iterator:";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::map<char, int>::iterator	it = first.begin();
	ft::map<char, int>::iterator	ite = first.end();
	while (it != ite)
	{
		std::cout << it->first << ": " << it->second << std::endl;
		it++;
	}

	std::cout << "\x1b[33m";
	std::cout << "Print 'first' map elements using reverse_iterator:";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::map<char, int>::reverse_iterator	rit = first.rbegin();
	ft::map<char, int>::reverse_iterator	rite = first.rend();
	while (rit != rite)
	{
		std::cout << rit->first << ": " << rit->second << std::endl;
		rit++;
	}

	std::cout << std::endl;
}

// Capacity
void	ft_test3(void)
{
	// Capacity
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>>>>> [ Capacity functions test ] <<<<<<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::map<char, int>				mymap;

	mymap['p'] = 100;
	mymap['a'] = 300;
	mymap['d'] = 500;
	mymap['m'] = 700;
	mymap['e'] = 900;

	std::cout << "\x1b[33m";
	std::cout << "Print 'mymap' map elements:";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::map<char, int>::iterator	it = mymap.begin();
	ft::map<char, int>::iterator	ite = mymap.end();
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
}

void	ft_test4(void)
{
	// Element access operator []
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>> [ Element access operator [] test ] <<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::map<char, int>				mymap;

	mymap['a'] = 10;
	mymap['b'] = 30;
	mymap['c'] = 50;
	mymap['d'] = 70;

	std::cout << "Print 'mymap' map elements using indexes:" << std::endl;
	std::cout << "mymap [a] is: " << mymap['a'] << std::endl;
	std::cout << "mymap [b] is: " << mymap['b'] << std::endl;
	std::cout << "mymap [c] is: " << mymap['c'] << std::endl;
	std::cout << "mymap [d] is: " << mymap['d'] << std::endl;

	std::cout << "mymap contains " << mymap.size() << " elements." << std::endl;

	std::cout << "Trying to access to non-existing element: " << mymap['x'];
   	std::cout << std::endl;

	std::cout << std::endl;
}

void	ft_test5(void)
{
	// Insert
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>> [ Insert function test ] <<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::map<char, int>		mymap;

	// First insert function version (single parameter):
	mymap.insert(std::pair<char, int>('a', 100));
	mymap.insert(std::pair<char, int>('z', 200));

	std::pair<ft::map<char, int>::iterator, bool>	ret;

	ret = mymap.insert(std::pair<char, int>('z', 500));
	if (ret.second == false)
	{
		std::cout << "Element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << std::endl;
	}

	// Second insert function version (with hint position):
	ft::map<char, int>::iterator	it = mymap.begin();
	mymap.insert(it, std::pair<char, int>('b', 300)); // max efficiency inserting
	mymap.insert(it, std::pair<char, int>('c', 400)); // no max efficiency inserting

	// Third insert function version (range insertion):
	ft::map<char, int>	anothermap;
	anothermap.insert(mymap.begin(), mymap.find('c'));

	// Showing contents:
	std::cout << "\x1b[33m";
	std::cout << "mymap contains:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "anothermap contains:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (it = anothermap.begin(); it != anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << std::endl;
}

void	ft_test6(void)
{
	// Erase
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>> [ Erase function test ] <<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;
	ft::map<char, int>				mymap;
	ft::map<char, int>::iterator	it;

	// Insert some values:
	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	mymap['d'] = 40;
	mymap['e'] = 50;
	mymap['f'] = 60;

	// Print initial map
	std::cout << "\x1b[33m";
	std::cout << "Initial map:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	// Erasing by iterator
	it = mymap.find('b');
	std::cout << "\x1b[33m";
	std::cout << "Erase by iterator pointing to 'b':";
	std::cout << "\033[0m\t\t" << std::endl;
	mymap.erase(it);
	// Print map
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	// Erasing by key
	std::cout << "\x1b[33m";
	std::cout << "Erase by key with value 'c':";
	std::cout << "\033[0m\t\t" << std::endl;
	mymap.erase('c');
	// Print map
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	// Erasing by range
	std::cout << "\x1b[33m";
	std::cout << "Erase by range from iterator pointing to 'e' to the end:";
	std::cout << "\033[0m\t\t" << std::endl;
	it = mymap.find('e');
	mymap.erase(it, mymap.end());
	// Print map
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "mymap size(): " << mymap.size() << std::endl; // test

	std::cout << std::endl;
}

void	ft_test7(void)
{
	// Swap
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>> [ Swap function test ] <<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::map<char, int>				foo;
	ft::map<char, int>				bar;
	ft::map<char, int>::iterator	it;

	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	// Print initial map 'foo'
	std::cout << "\x1b[33m";
	std::cout << "Initial map 'foo':";
	std::cout << "\033[0m\t\t" << std::endl;
	for (it = foo.begin(); it != foo.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	// Print initial map 'bar'
	std::cout << "\x1b[33m";
	std::cout << "Initial map 'bar':";
	std::cout << "\033[0m\t\t" << std::endl;
	for (it = bar.begin(); it != bar.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << std::endl;

	// Swap
	std::cout << "\x1b[33m";
	std::cout << "[ Swap 'foo' and 'bar' ]" << std::endl;
	std::cout << "\033[0m\t\t" << std::endl;
	foo.swap(bar);

	// Print map 'foo'
	std::cout << "\x1b[33m";
	std::cout << "Map 'foo' after swap:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (it = foo.begin(); it != foo.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	// Print initial map 'bar'
	std::cout << "\x1b[33m";
	std::cout << "Map 'bar' after swap:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (it = bar.begin(); it != bar.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << std::endl;
}

void	ft_test8(void)
{
	// Clear
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>> [ Clear function test ] <<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::map<char, int>				mymap;
	ft::map<char, int>::iterator	it;

	// Insert some values:
	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// Print initial map
	std::cout << "\x1b[33m";
	std::cout << "Initial map:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	// Clear
	mymap.clear();

	// Print map after clear function
	std::cout << "\x1b[33m";
	std::cout << "Map after clear function:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	// Add two new elements
	mymap['a'] = 1101;
	mymap['b'] = 2202;

	// Print map after adding new elements
	std::cout << "\x1b[33m";
	std::cout << "Map after adding two new elements:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << std::endl;
}

void	ft_test9(void)
{
	// key_comp
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>> [ Key_comp function test ] <<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::map<char, int>					mymap;
	ft::map<char, int>::key_compare		mycomp = mymap.key_comp();

	// Insert some values:
	mymap['a'] = 100;
	mymap['b'] = 200;
	mymap['c'] = 300;

	// Print initial map
	std::cout << "\x1b[33m";
	std::cout << "Print map using key_comp as a condition:";
	std::cout << "\033[0m\t\t" << std::endl;

	char	highest = mymap.rbegin()->first; // key value of lst element

	ft::map<char, int>::iterator	it = mymap.begin();

	do {
		std::cout << it->first << " => " << it->second << std::endl;
	} while (mycomp((*it++).first, highest));

	std::cout << std::endl;
}

void	ft_test10(void)
{
	// value_comp
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>> [ Value_comp function test ] <<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::map<char, int>					mymap;

	// Insert some values:
	mymap['x'] = 1001;
	mymap['y'] = 2002;
	mymap['z'] = 3003;

	// Print initial map
	std::cout << "\x1b[33m";
	std::cout << "Print map using key_comp as a condition:";
	std::cout << "\033[0m\t\t" << std::endl;

	// Last element
	std::pair<char, int>	highest = *mymap.rbegin();

	ft::map<char, int>::iterator	it = mymap.begin();

	do {
		std::cout << it->first << " => " << it->second << std::endl;
	} while (mymap.value_comp()(*it++, highest));

	std::cout << std::endl;
}

void	ft_test11(void)
{
	// Find
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>> [ Find function test ] <<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::map<char, int>				mymap;
	ft::map<char, int>::iterator	it;

	mymap['a'] = 50;
	mymap['b'] = 100;
	mymap['c'] = 150;
	mymap['d'] = 200;

	// Print initial map
	std::cout << "\x1b[33m";
	std::cout << "Initial map:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "Find 'b' and erase it:";
	std::cout << "\033[0m\t\t" << std::endl;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase(it);

	std::cout << "\x1b[33m";
	std::cout << "Left elements in mymap: ";
	std::cout << "\033[0m\t\t" << std::endl;
	// print content:
	std::cout << "a => " << mymap.find('a')->second << std::endl;
	std::cout << "b => " << mymap.find('b')->second << std::endl;
	std::cout << "c => " << mymap.find('c')->second << std::endl;
	std::cout << "d => " << mymap.find('d')->second << std::endl;

	std::cout << std::endl;
}

void	ft_test12(void)
{
	// Count
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>>>>>>> [ Count function test ] <<<<<<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::map<char, int>				mymap;
	ft::map<char, int>::iterator	it;
	char							c;

	mymap['a'] = 101;
	mymap['b'] = 202;
	mymap['c'] = 303;

	// Print initial map
	std::cout << "\x1b[33m";
	std::cout << "Initial map:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "Checking element existence using 'count' function:";
	std::cout << "\033[0m\t\t" << std::endl;

	for (c = 'a'; c < 'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c) > 0)
			std::cout << " is an element of mymap." << std::endl;
		else
			std::cout << " is not an element of mymap." << std::endl;
	}

	std::cout << std::endl;
}

void	ft_test13(void)
{
	// Lower_bound & Upper_bound
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>> [ Lower_bound & upper_bound functions test ] <<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::map<char, int>				mymap;
	ft::map<char, int>::iterator	it;
	ft::map<char, int>::iterator	itlow;
	ft::map<char, int>::iterator	itup;

	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;

	// Print initial map
	std::cout << "\x1b[33m";
	std::cout << "Initial map:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	// itlow points to 'b'
	itlow = mymap.lower_bound('b');

	std::cout << "\x1b[33m";
	std::cout << "itlow after lower_bound('b'): ";
	std::cout << "\033[0m\t\t" << std::endl;
	std::cout << itlow->first << " => " << itlow->second << std::endl;

	// itup points to 'e' (not 'd'!)
	itup = mymap.upper_bound('d');

	std::cout << "\x1b[33m";
	std::cout << "itup after upper_bound('d'): ";
	std::cout << "\033[0m\t\t" << std::endl;
	std::cout << itup->first << " => " << itup->second << std::endl;

	// Erase [itlow, itup)
	std::cout << "\x1b[33m";
	std::cout << "Map after erase [itlow, itup):";
	std::cout << "\033[0m\t\t" << std::endl;
	mymap.erase(itlow, itup);

	// Print initial map
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << std::endl;
}

void	ft_test14(void)
{
	// Equal_range
	std::cout << "\x1B[91m";
	std::cout << ">>>>>>> [ Equal_range functions test ] <<<<<<<";
	std::cout << "\033[0m\t\t" << std::endl;

	ft::map<char, int>				mymap;
	ft::map<char, int>::iterator	it;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

	// Print initial map
	std::cout << "\x1b[33m";
	std::cout << "Initial map:";
	std::cout << "\033[0m\t\t" << std::endl;
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator>	ret;
	std::cout << "\x1b[33m";
	std::cout << "[ Find equal_range('b') ]";
	std::cout << "\033[0m\t\t" << std::endl;
	ret = mymap.equal_range('b');

	std::cout << "\x1b[33m";
	std::cout << "lower bound points to:";
	std::cout << "\033[0m\t\t" << std::endl;
	std::cout << ret.first->first << " => " << ret.first->second << std::endl;

	std::cout << "\x1b[33m";
	std::cout << "upper bound points to:";
	std::cout << "\033[0m\t\t" << std::endl;
	std::cout << ret.second->first << " => " << ret.second->second << std::endl;

	std::cout << std::endl;
}

int		main(void)
{
	// Constructors
	ft_test1();

	// Iterators
	ft_test2();

	// Capacity
	ft_test3();

	// Element access operator []
	ft_test4();

	// Insert
	ft_test5();

	// Erase
	ft_test6();

	// Swap
	ft_test7();

	// Clear
	ft_test8();

	// key_comp
	ft_test9();

	// value_comp
	ft_test10();

	// Find
	ft_test11();

	// Count
	ft_test12();

	// Lower_bound & upper_bound
	ft_test13();

	// Equal_range
	ft_test14();
	
	return (0);
}
