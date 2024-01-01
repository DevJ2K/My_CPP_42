/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:44:32 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/01 02:11:46 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw(0), _bitsShift(8)
{
	std::cout << BHGREEN << "Default constructor called" << RESET << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src ) : _bitsShift(8)
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

}
int		Fixed::toInt( void ) const
{
	
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
