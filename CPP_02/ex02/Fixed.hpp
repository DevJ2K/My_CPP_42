/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:44:29 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/01 22:11:21 by tajavon          ###   ########.fr       */
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


	// 	Les 6 opérateur de comparaison : >, <, >=, <=, == et !=.
	bool	operator>(Fixed const & rhs) const;
	bool	operator<(Fixed const & rhs) const;
	bool	operator>=(Fixed const & rhs) const;
	bool	operator<=(Fixed const & rhs) const;
	bool	operator==(Fixed const & rhs) const;
	bool	operator!=(Fixed const & rhs) const;

	// • Les 4 opérateurs de arithmétiques : +, -, *, et /.
	Fixed	operator+(Fixed const & rhs) const;
	Fixed	operator-(Fixed const & rhs) const;
	Fixed	operator*(Fixed const & rhs) const;
	Fixed	operator/(Fixed const & rhs) const;

	// Les 4 opérateurs d’incrémentation et de décrémentation (pré-incrémentation et
	// post-incrémentation, pré-décrémentation et post-décrémentation) qui diminueront
	// la valeur du nombre à virgule fixe d’unité ϵ tel que 1 + ϵ > 1.

	// ++x;
	Fixed &	operator++( void );
	// x++;
	Fixed	operator++( int	);
	// --x;
	Fixed &	operator--( void );
	// x++;
	Fixed	operator--( int );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	static Fixed const & min( Fixed const & lhs, Fixed const & rhs );
	static Fixed& min( Fixed & lhs, Fixed & rhs );

	static Fixed const & max( Fixed const & lhs, Fixed const & rhs );
	static Fixed& max( Fixed & lhs, Fixed & rhs );

	int		getRawBits( void ) const; // Accesseur
	void	setRawBits( int const raw ); // Setteur
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
