/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:16:51 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 10:49:00 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <string>
#include "Array.hpp"

static void display_sub_line(std::string title)
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


#define MAX_VAL 750
int main(int, char**)
{
	display_sub_line("Called constructor");
	{
		Array<int>();
		Array<char> tabChar(10);
		for (int i = 0; i < 10; i++)
			tabChar[i] = static_cast<char>(i + 48);
		tabChar.display_array();

		Array<char> copyTabChar(tabChar);
		copyTabChar.display_array();
	}

	display_sub_line("2 dimensions tab constructor");
	{
		Array<int> *allocTab = new Array<int>[4];
		delete [] allocTab;
	}

	display_sub_line("Out Of Range Error");
	{
		Array<char> tabInt(5);
		for (int i = 0; i < 5; i++)
			tabInt[i] = i + 50;
		tabInt.display_array();
		try
		{
			tabInt[7] = 5;
		}
		catch(const std::exception& e)
		{
			display_err(e);
		}
	}

	display_sub_line("Assignation operator");
	{
		Array<std::string> phrase(4);
		phrase[0] = "salut";
		phrase[1] = "les";
		phrase[2] = "amis";
		phrase[3] = "!";
		phrase.display_array();

		Array<std::string> empty(0);

		Array<std::string> other_phrase(3);
		other_phrase[0] = "Hello";
		other_phrase[1] = "World";
		other_phrase[2] = "!";
		other_phrase.display_array();

		phrase = other_phrase;
		phrase.display_array();
		empty = other_phrase;
		empty.display_array();
	}
}
