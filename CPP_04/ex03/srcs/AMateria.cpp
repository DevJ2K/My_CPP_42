/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:01:05 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 14:04:19 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Colors.hpp"
#include <iostream>

AMateria::AMateria( std::string const & type )
{
	std::cout << BHGREEN << "AMateria Constructor called !" << RESET << std::endl;
	// this->type = "A_" + type;
	this->type = type;
	return ;
}

AMateria::AMateria(AMateria const & src)
{
	std::cout << BHYELLOW << "AMateria copy constructor called !" << RESET << std::endl;
	*this = src;
	return ;
}

AMateria::~AMateria()
{
	std::cout << BHRED << "AMateria Destructor called !" << RESET << std::endl;
	return ;
}

AMateria	&AMateria::operator=( AMateria const & rhs )
{
	this->type = rhs.getType();
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	if (this->type == "ice")
	{
		std::cout << BHCYAN << "Ice : * shoots an ice bolt at " RESET
		BHWHITE << target.getName() <<" *" << RESET << std::endl;
	}
	else if (this->type == "cure")
	{
		std::cout << BHYELLOW << "Cure : * heals " RESET
		BHWHITE << target.getName() <<"'s wounds *" << RESET << std::endl;
	}
	else
	{
		std::cout << REDHB << "an error encountered when you try to display AMateria : "
		<< this->getType() << RESET << std::endl;
	}

}