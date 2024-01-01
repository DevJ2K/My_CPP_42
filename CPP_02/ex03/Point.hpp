/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 23:44:16 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/02 00:02:56 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Colors.hpp"
#include <iostream>

class Point
{
private:
	Fixed	const _x;
	Fixed	const _y;
public:
	Point();
	Point( float const x, float const y );
	Point( Point & const src );
	~Point();

	Point	&operator=( Point & const rhs );

	Fixed	const getX( void );
	Fixed	const getY( void );
};
