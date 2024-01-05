/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:08:12 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 12:03:47 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
private:
	std::string	_type;
public:
	Ice();
	Ice( Ice const & src );
	virtual ~Ice();

	Ice	&operator=( Ice const & rhs );

	virtual Ice* clone( void ) const;
};

#endif