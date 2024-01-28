/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:10:20 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/28 13:49:56 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "PmergeMe.hpp"
#include <iostream>

void	display_err( std::string err_msg )
{
	std::cout << BHRED << "Error: " << RESET
	<< BRED << err_msg << RESET << std::endl;
}

int	main( int argc, char **argv )
{
	if (argc == 1)
		return (display_err("missing numbers."), 1);
	try
	{
		PmergeMe pmergeme((argc - 1), &argv[1]);
	}
	catch(const std::exception& e)
	{
		display_err(e.what());
		// std::cerr << e.what() << '\n';
	}
}
