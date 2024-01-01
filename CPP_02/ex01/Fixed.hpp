/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:44:29 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/01 14:39:49 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include "Colors.hpp"
# include <cmath>

class Fixed
{
private:
	int	_raw;
	static const int	_bitsShift = 8;
public:
	Fixed(); // Constructeur par défaut
	Fixed( int const n );
	Fixed( float const f );
	Fixed( Fixed const & src ); // Constructeur de recopie
	~Fixed(); // Destructeur

	Fixed	&operator=(Fixed const & rhs); // Surcharge d'opérateur d'affectation

	float	toFloat( void ) const;
	int		toInt( void ) const;

	int		getRawBits( void ) const; // Accesseur
	void	setRawBits( int const raw ); // Setteur
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
