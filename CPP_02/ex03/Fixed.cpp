/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:44:32 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/02 12:36:50 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw(0)
{
	// std::cout << BHGREEN << "Default constructor called" << RESET << std::endl;
	return ;
}

Fixed::Fixed( int const n ) : _raw( n << _bitsShift )
{
	// std::cout << BHBLUE << "Int constructor called" << RESET << std::endl;
	return ;
}

Fixed::Fixed( float const f ) : _raw( roundf(f * (1 << _bitsShift)) )
{
	// std::cout << BHBLUE << "Float constructor called" << RESET << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	// std::cout << BHYELLOW << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	// std::cout << BHRED << "Destructor called" << RESET << std::endl;
	return ;
}

Fixed	&Fixed::operator=(Fixed const & rhs)
{
	// std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	this->_raw = rhs.getRawBits();
	return *this;
}


// 	Les 6 opérateur de comparaison : >, <, >=, <=, == et !=.
bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}
bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}
bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}
bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}
bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}
bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

// • Les 4 opérateurs de arithmétiques : +, -, *, et /.
Fixed	Fixed::operator+(Fixed const & rhs) const
{
	return ( Fixed( this->toFloat() + rhs.toFloat()) );
}
Fixed	Fixed::operator-(Fixed const & rhs) const
{
	return ( Fixed( this->toFloat() - rhs.toFloat()) );
}
Fixed	Fixed::operator*(Fixed const & rhs) const
{
	return ( Fixed( this->toFloat() * rhs.toFloat()) );
}
Fixed	Fixed::operator/(Fixed const & rhs) const
{
	return ( Fixed( this->toFloat() / rhs.toFloat()) );
}

// Les 4 opérateurs d’incrémentation et de décrémentation (pré-incrémentation et
// post-incrémentation, pré-décrémentation et post-décrémentation) qui diminueront
// la valeur du nombre à virgule fixe d’unité ϵ tel que 1 + ϵ > 1.

// ++x
Fixed &	Fixed::operator++( void )
{
	this->_raw += 1;
	return (*this);
}
// x++
Fixed	Fixed::operator++( int )
{
	Fixed tmp( *this );
	this->_raw += 1;
	return (tmp);
}
// --x
Fixed &	Fixed::operator--( void )
{
	this->_raw -= 1;
	return (*this);
}
// x--
Fixed	Fixed::operator--( int )
{
	Fixed tmp( *this );
	this->_raw -= 1;
	return (tmp);
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
	// std::cout << BCYAN << "getRawBits member function called" << RESET << std::endl;
	return (this->_raw);
}

void	Fixed::setRawBits( int const raw )
{
	// std::cout << BCYAN << "setRawBits member function called" << RESET << std::endl;
	_raw = raw;
}


Fixed const & Fixed::min( Fixed const & lhs, Fixed const & rhs )
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}
Fixed& Fixed::min( Fixed & lhs, Fixed & rhs )
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed const & Fixed::max( Fixed const & lhs, Fixed const & rhs )
{
	if (lhs >= rhs)
		return (lhs);
	return (rhs);
}
Fixed& Fixed::max( Fixed & lhs, Fixed & rhs )
{
	if (lhs >= rhs)
		return (lhs);
	return (rhs);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
