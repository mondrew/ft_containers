/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mondrew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:58:24 by mondrew           #+#    #+#             */
/*   Updated: 2021/01/26 16:30:24 by mondrew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>

int		main(void)
{
	int		a = 5;
	int		*ptr = &a;
	int const	*cptr = &a;

	std::cout << "a: " << a << std::endl;
	*ptr = 3;
	std::cout << "After ptr a: " << a << std::endl;
	*cptr;
	std::cout << "After const ptr a: " << a << std::endl;

	return (0);
}
