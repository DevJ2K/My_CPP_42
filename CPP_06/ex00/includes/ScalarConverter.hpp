/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:33:33 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 14:59:36 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>
#include <istream>

enum e_type
{
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4,
	INFF = 5,
	INF = 6,
	NAN = 7,
	INVALID = 8
};

template <typename T>
T	getNb( std::string value )
{
	T nb;
	std::istringstream iss(value);

	iss >> nb;
	return (nb);
}

template <typename T>
bool	notOverflow( std::string value )
{
	T nb;
	std::istringstream iss(value);

	iss >> nb;
	return (iss.eof() && !iss.fail());
}

class ScalarConverter
{
private:

	ScalarConverter();

public:
	~ScalarConverter();

	static void	convert( std::string value );

};
