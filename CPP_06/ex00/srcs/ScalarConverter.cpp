/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:33:30 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/22 18:11:21 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "istream"

ScalarConverter::ScalarConverter(/* args */)
{
}

ScalarConverter::~ScalarConverter()
{
}


void	ScalarConverter::convert( std::string value )
{
	e_type type = CHAR;

	switch (type)
	{
	case CHAR:
		std::cout << "char: " << static_cast<char>(value[0]) << std::endl;
		std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
		std::cout << "float: " << static_cast<char>(value[0]) << std::endl;
		std::cout << "double: " << static_cast<char>(value[0]) << std::endl;
		break;
	case INT:
		std::cout << "char: " << static_cast<char>(value[0]) << std::endl;
		std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
		std::cout << "float: " << static_cast<char>(value[0]) << std::endl;
		std::cout << "double: " << static_cast<char>(value[0]) << std::endl;
		break;
	case FLOAT:
		std::cout << "char: " << static_cast<char>(value[0]) << std::endl;
		std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
		std::cout << "float: " << static_cast<char>(value[0]) << std::endl;
		std::cout << "double: " << static_cast<char>(value[0]) << std::endl;
		break;
	case DOUBLE:
		std::cout << "char: " << static_cast<char>(value[0]) << std::endl;
		std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
		std::cout << "float: " << static_cast<char>(value[0]) << std::endl;
		std::cout << "double: " << static_cast<char>(value[0]) << std::endl;
		break;
	case INVALID:
		std::cout << "invalid format or overflow ! " << std::endl;
		break;
	}

}
