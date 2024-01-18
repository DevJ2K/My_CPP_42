/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:19:10 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/18 14:16:15 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Colors.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("lambda", 145, 137),
	_target("lambda")
{
	std::cout << GREEN << "Default constructor ShrubberyCreation was called !" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm(target, 145, 137)
{
	this->_target = target;
	std::cout << BHGREEN << this->_target << RESET << BGREEN << ", was created !" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : AForm(src.getTarget(), 145, 137)
{
	std::cout << BYELLOW << "Copy constructor ShrubberyCreation was called !" << RESET << std::endl;
	this->_target = src.getTarget();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BHRED << this->_target << RESET << BRED << ", was destroyed !" << RESET << std::endl;
}

ShrubberyCreationForm& 	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	this->_target = rhs.getTarget();
	return (*this);
}

void	ShrubberyCreationForm::customExecute( void ) const
{
	std::cout << "I executed Shrubbery Code !" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}
