/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 23:44:14 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/02 00:05:25 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point( float const x, float const y ) : _x(x), _y(y)
{
	std::cout << "Point constructor called with parameters "
	<< "[x: " << x << "] | "
	<< "[y: " << y << "]";
}

Point::Point( Point & const src ) : _x( src.getX() ), _y( src.getY() )
{
}

Point::~Point()
{
}

Point&	Point::operator=( Point & const rhs )
{
}

Fixed	const Point::getX( void )
{
	return (this->_x);
}
Fixed	const Point::getY( void )
{
	return (this->_y);
}
