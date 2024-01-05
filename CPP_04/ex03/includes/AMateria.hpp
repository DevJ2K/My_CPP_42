/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:00:56 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 13:32:01 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	type;
public:
	AMateria( std::string const & type );
	AMateria(AMateria const & src);
	virtual ~AMateria();

	virtual AMateria	&operator=( AMateria const & rhs );

	std::string const & getType() const; //Returns the materia type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif