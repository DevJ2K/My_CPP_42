/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:36:57 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 14:52:13 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include "Colors.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);

	std::cout << BHCYAN << "======ENUMTYPE======" << std::endl;
	std::cout << "CHAR : 1" << std::endl;
	std::cout << "INT : 2" << std::endl;
	std::cout << "FLOAT : 3" << std::endl;
	std::cout << "DOUBLE : 4" << std::endl;
	std::cout << "INVALID : 5" << std::endl;
	std::cout << "====================" << RESET << std::endl;

	std::string str = argv[1];
	ScalarConverter::convert(str);
}
