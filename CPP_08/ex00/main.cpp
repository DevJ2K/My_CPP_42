/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:47:20 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/25 16:11:14 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <iterator>
#include <iostream>
#include "easyfind.hpp"
#include "Colors.hpp"

int	main( void )
{
	int	nb_elements = 30;

	std::list<int> tabInt;
	for (int i = 0; i < nb_elements; i++)
	{
		if (i % 2 == 0)
			tabInt.push_back(i);
	}

	for (int i = 0; i < nb_elements; i++)
	{
		try
		{
			std::list<int>::const_iterator it = easyfind(tabInt, i);
			std::cout << BHCYAN << *it << " is in the tab !" << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << BHRED << i << " : " << e.what() << RESET << '\n';
		}
	}
}
