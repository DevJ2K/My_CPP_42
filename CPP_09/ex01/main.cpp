/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:10:20 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/27 22:25:36 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "RPN.hpp"
#include <iostream>

void	display_err( std::string err_msg )
{
	std::cout << BHRED << "Error: " << RESET
	<< BRED << err_msg << RESET << std::endl;
}

int	main( int argc, char **argv )
{
	if (argc == 1)
		return (display_err("missing calcul."), 1);
	if (argc != 2)
		return (display_err("too many arguments."), 1);
	try
	{
		RPN rpn(argv[1]);
		rpn.executeCalcul();
	}
	catch(const std::exception& e)
	{
		display_err(e.what());
		// std::cerr << e.what() << '\n';
	}
}
