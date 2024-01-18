/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:19:10 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/18 19:09:34 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Colors.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("lambda", 25, 5),
	_target("lambda")
{
	std::cout << GREEN << "Default constructor PresidentialPardon was called !" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm(target, 25, 5)
{
	this->_target = target;
	std::cout << BHGREEN << this->_target << RESET << BGREEN << ", was created !" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : AForm(src.getTarget(), 25, 5)
{
	std::cout << BYELLOW << "Copy constructor PresidentialPardon was called !" << RESET << std::endl;
	this->_target = src.getTarget();
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BHRED << this->_target << RESET << BRED << ", was destroyed !" << RESET << std::endl;
}

PresidentialPardonForm& 	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	this->_target = rhs.getTarget();
	return (*this);
}

void	PresidentialPardonForm::customExecute( void ) const
{
	std::cout << BHMAG << this->_target << RESET << BHWHITE
	<<  " has been pardoned by " << RESET
	<< BHBLUE << "Zaphod Beeblebrox" << RESET << "." << std::endl;
}

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}
