/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:47:20 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/24 14:45:13 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <iterator>
#include "easyfind.hpp"
#include "Colors.hpp"

int	main( void )
{
	std::list<int> tabInt;
	for (int i = 0; i < 20; i++)
	{
		if (i % 2 == 0)
			tabInt.push_back(i);
	}

	for (int i = 0; i < 20; i++)
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
