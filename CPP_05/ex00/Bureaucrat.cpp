/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:57:21 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/17 14:53:38 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Colors.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
	std::cout << BHMAG << this->_name << RESET
	<< BHWHITE << ", new bureaucrat is born !"
	<< RESET << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << BHRED << this->_name << RESET
	<< BRED << ", was destroyed." << RESET << std::endl;
}

int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

void	Bureaucrat::increaseGrade( void )
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
}
void	Bureaucrat::decreaseGrade( void )
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << BMAG << rhs.getName() << RESET
	<< ", bureaucrat grade " << BHYELLOW
	<<  rhs.getGrade() << RESET << "." << std::endl;
	return (o);
}
