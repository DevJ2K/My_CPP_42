/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:29:59 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 12:03:49 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
private:
	std::string	_type;
public:
	Cure();
	Cure( Cure const & src );
	virtual ~Cure();

	Cure	&operator=( Cure const & rhs );

	virtual Cure* clone( void ) const;
};

#endif