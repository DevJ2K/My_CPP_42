/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:44:32 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/02 12:14:27 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw(0)
{
	std::cout << BHGREEN << "Default constructor called" << RESET << std::endl;
	return ;
}

Fixed::Fixed( int const n ) : _raw( n << _bitsShift )
{
	std::cout << BHBLUE << "Int constructor called" << RESET << std::endl;
	return ;
}

Fixed::Fixed( float const f ) : _raw( roundf(f * (1 << _bitsShift)) )
{
	std::cout << BHBLUE << "Float constructor called" << RESET << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << BHYELLOW << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << BHRED << "Destructor called" << RESET << std::endl;
	return ;
}

Fixed	&Fixed::operator=(Fixed const & rhs)
{
	std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	this->_raw = rhs.getRawBits();
	return *this;
}

float	Fixed::toFloat( void ) const
{
	return ( (float)this->_raw / (1 << Fixed::_bitsShift) );
}
int		Fixed::toInt( void ) const
{
	return ( this->_raw >> Fixed::_bitsShift );
}

int	Fixed::getRawBits( void ) const
{
	std::cout << BCYAN << "getRawBits member function called" << RESET << std::endl;
	return (this->_raw);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << BCYAN << "setRawBits member function called" << RESET << std::endl;
	_raw = raw;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
