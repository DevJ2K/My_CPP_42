/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:44:32 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/30 22:10:16 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw(0), _bitsShift(8)
{

}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits( void ) const
{
	return (this->_raw);
}

void	Fixed::setRawBits( int const raw )
{
	_raw = raw;
}
