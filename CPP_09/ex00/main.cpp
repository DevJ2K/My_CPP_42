/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:41:01 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/28 16:21:06 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Colors.hpp"
#include <iostream>

void	display_err( std::string err_msg )
{
	std::cout << BHRED << "Error: " << RESET
	<< BRED << err_msg << RESET << std::endl;
}

void	display_big_line( std::string colors, std::string text )
{
	size_t line_size = 30 - (text.length() / 2);
	std::cout << std::endl;
	for (size_t i = 0; i < line_size; i++)
		std::cout << BHWHITE "=" RESET;

	std::cout << colors << text << RESET;

	for (size_t i = 0; i < line_size; i++)
		std::cout << BHWHITE "=" RESET;
	std::cout << std::endl << std::endl;
}

int	main( int argc, char **argv )
{
	if (argc == 1)
		return (display_err("missing input file."), 1);
	if (std::strcmp(argv[1], "-F") == 0
	|| std::strcmp(argv[1], "-files") == 0)
	{
		for (int i = 2; i < argc; i++)
		{
			try
			{
				display_big_line(BHCYAN, argv[i]);
				BitcoinExchange btc(DATA_FILE ,argv[i]);
			}
			catch(const std::exception& e)
			{
				// std::cout << e.what() << '\n';
			}
		}
		return (0);
	}
	else if (argc != 2)
		return (display_err("too many arguments."), 1);
	try
	{
		display_big_line(BHCYAN, argv[1]);
		BitcoinExchange btc(DATA_FILE ,argv[1]);
	}
	catch(const std::exception& e)
	{
		// std::cout << e.what() << '\n';
	}

}
