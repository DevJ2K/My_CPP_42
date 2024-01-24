/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:32:51 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/24 09:51:19 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "Colors.hpp"
#include <iostream>

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

void	display_int(int nb)
{
	std::cout << BHMAG << nb << " - " << RESET;
}

void	display_char_star(char *str)
{
	std::cout << BHBLUE << str << " - " << RESET;
}

void	display_string(std::string str)
{
	std::cout << BHGREEN << str << " - " << RESET;
}

int	main(int argc, char **argv)
{
	display_sub_line("Display Arguments");
	iter(argv, argc, &display_char_star);
	std::cout << std::endl;

	display_sub_line("Display Tab Int");
	int tabInt[5] = {1, 2, 3, 4, 5};
	iter(tabInt, 5, &display_int);
	std::cout << std::endl;

	display_sub_line("Display String");
	std::string tabString[3] = {
		"salut",
		"les",
		"amis",
	};
	iter(tabString, 3, &display_string);
	std::cout << std::endl;




}
