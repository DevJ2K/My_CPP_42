/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:38:53 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 16:42:54 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Colors.hpp"
#include <iostream>

Data::Data()
{
}

Data::Data( int day, std::string month, int year ) :
_day(day), _month(month), _year(year)
{
	std::cout << BHGREEN << "Data created !" << RESET << std::endl;
	this->displayData();
}

Data::Data( Data const &src )
{
	std::cout << BGREEN "New Data created by copie !" << RESET << std::endl;
	*this = src;
	this->displayData();
}

void	Data::displayData( void ) const
{
	std::cout << BHBLACK << &(*this) << " -> (UINTPTR_T)" << reinterpret_cast<uintptr_t>(&(*this))
	<< " : " RESET BHWHITE "You birth is the " RESET BHCYAN << this->_day
	<< RESET " " BHYELLOW << this->_month <<  RESET " " BHMAG
	<< this->_year << RESET << BHWHITE " !" RESET << std::endl;
}

Data	&Data::operator=( Data const &rhs )
{
	if (this != &rhs)
	{
		this->_day = rhs.getDay();
		this->_month = rhs.getMonth();
		this->_year = rhs.getYear();
	}
	return (*this);
}

int			Data::getDay( void ) const
{
	return (this->_day);
}

std::string	Data::getMonth( void ) const
{
	return (this->_month);
}

int			Data::getYear( void ) const
{
	return (this->_year);
}

Data	*Data::deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}

Data::~Data()
{
	std::cout << BHRED << "Data destroyed !" << RESET << std::endl;
}
