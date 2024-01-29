/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomInt.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:56:39 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/29 09:39:51 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_INT_HPP
# define CUSTOM_INT_HPP

#include <ostream>

class CustomInt
{
private:
	double		_value;
	bool	_isSign;
	CustomInt();
public:
	CustomInt( double value, bool isSign );
	CustomInt( CustomInt const & src );
	~CustomInt();

	CustomInt	&operator=( CustomInt const & rhs );
	double		getValue( void ) const;
	bool	getIsSign( void ) const;

};

std::ostream	&operator<<( std::ostream & o, CustomInt const & src );

#endif
