/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomInt.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:04:51 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/27 22:14:52 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CustomInt.hpp"


CustomInt::CustomInt() : _value(0), _isSign(0)
{
}

CustomInt::CustomInt( CustomInt const & src )
{
	*this = src;
}

CustomInt::CustomInt( int value, bool isSign ) : _value(value), _isSign(isSign)
{
}

CustomInt::~CustomInt()
{
}

int		CustomInt::getValue( void ) const
{
	return (this->_value);
}
bool	CustomInt::getIsSign( void ) const
{
	return (this->_isSign);
}

CustomInt	&CustomInt::operator=( CustomInt const & rhs )
{
	this->_value = rhs.getValue();
	this->_isSign = rhs.getIsSign();
	return (*this);
}

std::ostream	&operator<<( std::ostream & o, CustomInt const & src )
{
	if (src.getIsSign() == true)
		o << static_cast<char>(src.getValue());
	else
		o << src.getValue();
	return (o);
}
