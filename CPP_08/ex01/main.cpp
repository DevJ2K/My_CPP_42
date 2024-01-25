/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:48:36 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/25 16:00:22 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Colors.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <list>
#include <algorithm>

void display_sub_line(std::string title)
{
	size_t line_size = 30;

	std::cout << std::endl;

	for (size_t i = 0; i < (line_size - title.length()) / 2; i++)
		std::cout << BHWHITE << "=" << RESET;

	std::cout << BHCYAN << title << RESET;

	for (size_t i = 0; i < (line_size - title.length()) / 2; i++)
		std::cout << BHWHITE << "=" << RESET;

	std::cout << std::endl;
	std::cout << std::endl;
	return;
}

void display_err(const std::exception &e)
{
	std::cerr << BHRED << "An error was catch: " << RESET BRED << e.what() << RESET << std::endl;
}

void	display_span(Span sp)
{
	std::cout << BHWHITE << sp.getNbElements() << ": [ " << RESET;
	for (unsigned int i = 0; i < sp.getNbElements(); i++)
	{
		std::cout << BHMAG << sp[i] << RESET;
		if (i + 1 < sp.getNbElements())
			std::cout << " - ";
	}
	std::cout << BHWHITE " [" << RESET << std::endl;

}

int main()
{
	std::srand(time(NULL));
	Span notEnough = Span(1);
	display_sub_line("Not Enough Numbers");
	try
	{
		std::cout << notEnough.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		display_err(e);
	}
	notEnough.addNumber(1);
	try
	{
		std::cout << notEnough.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		display_err(e);
	}

	display_sub_line("Mandatory");
	Span sp = Span(15);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	display_span(sp);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	display_sub_line("Adding new numbers list");
	std::list<int> list1;
	std::list<int> list2;
	for (int i = 0; i < 5; i++)
		list1.push_back(std::rand() % 20);

	sp.addNumbers(list1.begin(), list1.end());
	display_span(sp);

	std::cout << BHWHITE "New Longest Span : " RESET BHCYAN << sp.longestSpan() << RESET << std::endl;
	std::cout << BHWHITE "New Shortest Span : " RESET BHCYAN << sp.shortestSpan() << RESET << std::endl;

	display_sub_line("Error adding to many numbers");
	try
	{
		for (size_t i = 0; i < 50000; i++)
		{
			sp.addNumber(i);
		}

	}
	catch(const std::exception& e)
	{
		display_span(sp);
		display_err(e);
	}

	display_sub_line("Big Span");
	Span bigSpan(20000);
	for (size_t i = 0; i < 20000; i++)
	{
		bigSpan.addNumber(1);
	}
	// display_span(bigSpan);

	display_sub_line("addind error again");
	try
	{
		bigSpan.addNumber(10);
	}
	catch(const std::exception& e)
	{
		display_err(e);
	}


	return 0;
}
