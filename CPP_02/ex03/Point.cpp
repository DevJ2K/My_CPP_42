/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 23:44:14 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/02 12:36:35 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	return ;
}

Point::Point( float const x, float const y ) : _x(Fixed(x)), _y(Fixed(y))
{
	// std::cout << "Point constructor called with parameters "
	// << "[x: " << x << "] | "
	// << "[y: " << y << "]" << std::endl;
	return ;
}

Point::Point( Point const & src ) : _x( src.getX() ), _y( src.getY() )
{
	// std::cout << "Point constructor called by copie with parameters "
	// << "[x: " << src.getX() << "] | "
	// << "[y: " << src.getY() << "]" << std::endl;
	return ;
}

Point::~Point()
{
	// std::cout << BHRED << "Point "
	// << "[x: " << this->getX() << "] | "
	// << "[y: " << this->getY() << "] was destroyed !" << RESET << std::endl;
	return ;
}

Point&	Point::operator=( Point const & rhs )
{
	(void)rhs;
	// std::cout << BRED << "Impossible to assign because Point class have only const parameters." << RESET << std::endl;
	return (*this);
}

Fixed	const Point::getX( void ) const
{
	return (this->_x);
}
Fixed	const Point::getY( void ) const
{
	return (this->_y);
}
