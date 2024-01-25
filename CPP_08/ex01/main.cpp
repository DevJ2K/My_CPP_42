/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:48:36 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/25 13:06:54 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <list>

void	display_span(Span sp)
{
	std::cout << std::endl << sp.getNbElements() << ": [ ";
	for (unsigned int i = 0; i < sp.getNbElements(); i++)
	{
		std::cout << sp[i] << " - ";
	}
	std::cout << "[" << std::endl;

}

int main()
{
	Span sp = Span(8);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	display_span(sp);

	std::list<int> list1;
	std::list<int> list2;
	for (int i = 0; i < 3; i++)
		list1.push_back(i);

	sp.addNumbers(list1.begin(), list2.end());
	display_span(sp);
	// std::cout << sp.shortestSpan() << std::endl;
	return 0;
}

// int	main( void )
// {
// 	std::list<int> mylist;

// 	std::cout << mylist.max_size() << std::endl;
// }
