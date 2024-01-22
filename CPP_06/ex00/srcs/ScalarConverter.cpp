/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:33:30 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/22 18:31:08 by tajavon          ###   ########.fr       */
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

static e_type	getType( std::string value )
{
	if (value.length() == 1 && !std::isdigit(value[0]))
		return (CHAR);
	else if (value.length() == 1 && isdigit(value[0]))
		return (INT);
	else if (value.length() == 3 && value[0] == 'f' && value[1] == 'f' && value[2] == 'f')
		return (FLOAT);
	else if (value.length() == 3 && value[0] == 'f' && value[1] == 'f' && value[2] == 'f')
		return (DOUBLE);
	else
		return (INVALID);
}

void	ScalarConverter::convert( std::string value )
{
	e_type type = getType(value);

	switch (type)
	{
	case CHAR:
		char c;
		c = static_cast<char>(value[0]);
		if (c == 0)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(value[0]) << "'" << std::endl;

		std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(value[0]) << ".0f"<< std::endl;
		std::cout << "double: " << static_cast<double>(value[0]) << ".0"<< std::endl;
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
