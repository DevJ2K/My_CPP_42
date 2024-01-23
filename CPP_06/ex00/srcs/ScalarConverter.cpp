/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:33:30 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 15:33:43 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Colors.hpp"
#include <limits>
#include <sstream>
#include <istream>
#include <iomanip>

ScalarConverter::ScalarConverter(/* args */)
{}
ScalarConverter::~ScalarConverter()
{}

// ##############################################################
// #   Check Format                                             #
// ##############################################################

static bool	isInIntFormat( std::string value )
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

static int	isInDecimalFormat( std::string value )
{
	int nb_point = 0;
	for (size_t i = 0; i < value.length() - 1; i++)
	{
		if (std::isdigit(value.c_str()[i]))
			continue ;
		else if (i == 0 && (value.c_str()[i] == '-' || value.c_str()[i] == '+'))
			continue ;
		else if (value.c_str()[i] == '.')
		{
			nb_point++;
			continue ;
		}
		else
			return (0);
	}
	if (nb_point > 1)
		return (0);
	if (value.c_str()[value.length() - 1] != 'f' && std::isdigit(value.c_str()[value.length() - 1]))
		return (2);
	else if (value.c_str()[value.length() - 1] == 'f')
		return (1);
	else
		return (0);
}

static bool	isInInfFormat( std::string value )
{
	return (value == "inf" || value == "+inf" || value == "-inf");
}

static bool isInInffFormat( std::string value )
{
	return (value == "inff" || value == "+inff" || value == "-inff");
}

static bool isInNanFormat( std::string value )
{
	return (value == "nan" || value == "NaN");
}

static bool isInNanfFormat( std::string value )
{
	return (value == "nanf" || value == "NaNf");
}

static e_type	getType( std::string value )
{
	if (value.length() == 1 && !std::isdigit(value[0]))
		return (CHAR);
	else if (isInIntFormat(value))
		return (INT);
	else if (isInDecimalFormat(value) == 1)
		return (FLOAT);
	else if (isInDecimalFormat(value) == 2)
		return (DOUBLE);
	else if (isInInffFormat(value))
		return (INFF);
	else if (isInInfFormat(value))
		return (INF);
	else if (isInNanFormat(value))
		return (NAN);
	else if (isInNanfFormat(value))
		return (NANF);
	else
		return (INVALID);
}

static void	display_format( e_type type )
{
	std::cout << BHCYAN << "======ENUMTYPE======" << std::endl;
	std::cout << BHMAG "CHAR : 1" RESET << std::endl;
	std::cout << BHBLUE "INT : 2" RESET << std::endl;
	std::cout << BHCYAN "FLOAT : 3" RESET << std::endl;
	std::cout << BHGREEN "DOUBLE : 4" RESET << std::endl;
	std::cout << BHYELLOW "INFF : 5" RESET << std::endl;
	std::cout << BYELLOW "INF : 6" RESET << std::endl;
	std::cout << BRED "NANF : 7" RESET << std::endl;
	std::cout << BRED "NAN : 8" RESET << std::endl;
	std::cout << BHRED "INVALID : 9" RESET << std::endl;
	std::cout << BHWHITE "====================" << RESET << std::endl;
	std::cout << BHWHITE << "INPUT TYPE : " RESET;
	switch (type)
	{
		case CHAR:
			std::cout << BHMAG "CHAR" RESET << std::endl;
			break;
		case INT:
			std::cout << BHBLUE "INT" RESET << std::endl;
			break;
		case FLOAT:
			std::cout << BHCYAN "FLOAT" RESET << std::endl;
			break;
		case DOUBLE:
			std::cout << BHGREEN "DOUBLE" RESET << std::endl;
			break;
		case INFF:
			std::cout << BHYELLOW "FLOAT - INFF" RESET << std::endl;
			break;
		case INF:
			std::cout << BYELLOW "DOUBLE - INF" RESET << std::endl;
			break;
		case NANF:
			std::cout << BRED "NANF" RESET << std::endl;
			break;
		case NAN:
			std::cout << BRED "NAN" RESET << std::endl;
			break;
		case INVALID:
			std::cout << BHRED "INVALID" RESET << std::endl;
			break;
	}
}

void	ScalarConverter::convert( std::string value )
{
	e_type type = getType(value);
	display_format(type);
	switch (type)
	{
	case CHAR:
		char c;
		c = static_cast<char>(value[0]);
		if (std::isprint(c) == 0)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;

		std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(value[0]) << ".0f"<< std::endl;
		std::cout << "double: " << static_cast<double>(value[0]) << ".0"<< std::endl;
		break;
	case INT:
		if (notOverflow<int>(value) == 1)
		{
			std::cout << std::fixed << std::setprecision(1);
			char c;
			c = static_cast<char>(getNb<int>(value));
			if (std::isprint(c) == 0)
				std::cout << "char: Non displayable" << std::endl;
			else if (getNb<int>(value) < 0 || getNb<int>(value) > 127)
				std::cout << "char: impossible" << std::endl;
			else
				std::cout << "char: '" << c << "'" << std::endl;
			std::cout << "int: " << getNb<int>(value) << std::endl;
			std::cout << "float: " << static_cast<float>(getNb<int>(value)) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(getNb<int>(value)) << std::endl;
		}
		else
			std::cout << BHRED "Impossible to convert due to an overflow !" RESET << std::endl;
		break;
	case FLOAT:
		if (notOverflow<float>(value.substr(0, value.length() - 1)) == 1)
		{
			int precision = value.length() - value.find('.') - 2;
			std::cout << std::fixed << std::setprecision(precision);
			char c;
			c = static_cast<char>(getNb<float>(value));
			if (std::isprint(c) == 0)
				std::cout << "char: Non displayable" << std::endl;
			else if (getNb<float>(value) < 0 || getNb<float>(value) > 127)
				std::cout << "char: impossible" << std::endl;
			else
				std::cout << "char: '" << c << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(getNb<float>(value)) << std::endl;
			std::cout << "float: " << getNb<float>(value) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(getNb<float>(value)) << std::endl;
		}
		else
			std::cout << BHRED "Impossible to convert due to an overflow !" RESET << std::endl;
		break;
	case DOUBLE:
		if (notOverflow<double>(value.substr(0, value.length() - 1)) == 1)
		{
			int precision = value.length() - value.find('.') - 1;
			std::cout << std::fixed << std::setprecision(precision);
			char c;
			c = static_cast<char>(getNb<double>(value));
			if (std::isprint(c) == 0)
				std::cout << "char: Non displayable" << std::endl;
			else if (getNb<double>(value) < 0 || getNb<double>(value) > 127)
				std::cout << "char: impossible" << std::endl;
			else
				std::cout << "char: '" << c << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(getNb<double>(value)) << std::endl;
			std::cout << "float: " << static_cast<float>(getNb<double>(value)) << "f" << std::endl;
			std::cout << "double: " << getNb<double>(value) << std::endl;
		}
		else
			std::cout << BHRED "Impossible to convert due to an overflow !" RESET << std::endl;
		break;
	case INFF:
		float floatInf;
		if (value[0] == '-')
			floatInf = -std::numeric_limits<float>::infinity();
		else
			floatInf = std::numeric_limits<float>::infinity();

		std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << "undefined behavior" << std::endl;
		std::cout << "float: " << floatInf << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(floatInf) << std::endl;
		break;
	case INF:
		double doubleInf;
		if (value[0] == '-')
			doubleInf = -std::numeric_limits<double>::infinity();
		else
			doubleInf = std::numeric_limits<double>::infinity();

		std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << "undefined behavior" << std::endl;
		std::cout << "float: " << static_cast<float>(doubleInf) << "f" << std::endl;
		std::cout << "double: " << doubleInf << std::endl;
		break;
	case NANF:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		break;
	case NAN:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		break;
	case INVALID:
		std::cout << BHRED << "invalid format ! " << RESET << std::endl;
		break;
	}

}
