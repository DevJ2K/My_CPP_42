/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomInt.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:56:39 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/27 22:15:38 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_INT_HPP
# define CUSTOM_INT_HPP

#include <ostream>

class CustomInt
{
private:
	int		_value;
	bool	_isSign;
	CustomInt();
public:
	CustomInt( int value, bool isSign );
	CustomInt( CustomInt const & src );
	~CustomInt();

	CustomInt	&operator=( CustomInt const & rhs );
	int		getValue( void ) const;
	bool	getIsSign( void ) const;

};

std::ostream	&operator<<( std::ostream & o, CustomInt const & src );

#endif
