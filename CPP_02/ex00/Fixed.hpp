/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:44:29 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/01 02:02:46 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include "Colors.hpp"

class Fixed
{
private:
	int	_raw;
	const int	_bitsShift;
public:
	Fixed(); // Constructeur par défaut
	Fixed( Fixed const & src ); // Constructeur de recopie
	~Fixed(); // Destructeur

	Fixed	&operator=(Fixed const & rhs); // Surcharge d'opérateur d'affectation

	int		getRawBits( void ) const; // Accesseur
	void	setRawBits( int const raw ); // Setteur
};

#endif
