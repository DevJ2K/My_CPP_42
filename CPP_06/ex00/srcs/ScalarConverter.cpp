/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:33:30 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 12:11:22 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Colors.hpp"
#include <sstream>
#include <istream>
#include <iomanip>

ScalarConverter::ScalarConverter(/* args */)
{}
ScalarConverter::~ScalarConverter()
{}
bool notIntOverflow( std::string value )
{
	int nb;
	std::istringstream iss(value);

	iss >> nb;
	// std::cout << "ENVOIE REUSSI : " << iss.eof() << " | PAS DE FAILS " << !iss.fail() << std::endl;
	return (iss.eof() && !iss.fail());
}

int	getInt( std::string value )
{
	int nb;
	std::istringstream iss(value);

	iss >> nb;
	return (nb);
}

bool	isInIntFormat( std::string value )
{
	for (size_t i = 0; i < value.length(); i++)
	{
		if (std::isdigit(value.c_str()[i]))
			continue ;
		else if (i == 0 && (value.c_str()[i] == '-' || value.c_str()[i] == '+'))
			continue ;
		else
			return (false);
	}
	return (true);
}

static e_type	getType( std::string value )
{
	if (value.length() == 1 && !std::isdigit(value[0]))
		return (CHAR);
	else if (isInIntFormat(value))
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
	std::cout << BHWHITE << "TYPE : " RESET BHCYAN << type << RESET << std::endl;

	notIntOverflow(value);

	std::cout << std::fixed << std::setprecision(9);


	switch (type)
	{
	case CHAR:
		char c;
		c = static_cast<char>(value[0]);
		if (std::isprint(c) == 0)
			std::cout << "char: Non displayable" << std::endl;
		else

		std::cout << "char: '" << static_cast<char>(value[0]) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(value[0]) << ".0f"<< std::endl;
		std::cout << "double: " << static_cast<double>(value[0]) << ".0"<< std::endl;
		break;
	case INT:
		std::cout << "char: " << static_cast<char>(value[0]) << std::endl;
		if (notIntOverflow(value) == 1)
			std::cout << "int: " << getInt(value) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(getInt(value)) << std::endl;
		std::cout << "double: " << static_cast<double>(getInt(value)) << std::endl;
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
