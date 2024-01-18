/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:19:10 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/18 19:20:03 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Colors.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("lambda", 72, 45),
	_target("lambda")
{
	std::cout << GREEN << "Default constructor RobotomyRequest was called !" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm(target, 72, 45)
{
	this->_target = target;
	std::cout << BHGREEN << this->_target << RESET << BGREEN << ", was created !" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : AForm(src.getTarget(), 72, 45)
{
	std::cout << BYELLOW << "Copy constructor RobotomyRequest was called !" << RESET << std::endl;
	this->_target = src.getTarget();
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << BHRED << this->_target << RESET << BRED << ", was destroyed !" << RESET << std::endl;
}

RobotomyRequestForm& 	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	this->_target = rhs.getTarget();
	return (*this);
}

void	RobotomyRequestForm::customExecute( void ) const
{
	std::srand(time(NULL));
	int nb = std::rand() % 2; // Un nombre entre 0 et 1.
	if (nb)
		std::cout << BHGREEN << this->getTarget() << RESET << BHWHITE
		<< " has been robotomized !" << RESET << std::endl;
	else
		std::cout << BHWHITE << "Failed to robotomize the target : " << RESET
		<< BHRED << this->getTarget() << std::endl;
}

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}
