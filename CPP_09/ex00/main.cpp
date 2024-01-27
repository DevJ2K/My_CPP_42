/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:41:01 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/27 14:01:45 by tajavon          ###   ########.fr       */
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

int	main( int argc, char **argv )
{
	if (argc == 1)
		return (display_err("missing input file."), 1);
	if (argc != 2)
		return (display_err("too many arguments."), 1);
	try
	{
		BitcoinExchange btc(DATA_FILE ,argv[1]);
	}
	catch(const std::exception& e)
	{// std::cerr << e.what() << '\n';
	}

}
