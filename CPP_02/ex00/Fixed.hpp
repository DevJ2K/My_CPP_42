/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:44:29 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/30 22:14:03 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int	_raw;
	const int	_bitsShift;
public:
	Fixed();
	~Fixed();

	// int operator=(const Fixed &);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif
