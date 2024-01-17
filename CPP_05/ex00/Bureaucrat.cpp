/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:57:21 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/17 15:24:40 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Colors.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat( void ) : _name("No_name"), _grade(1)
{
	std::cout << BGREEN << "Default constructor called !" << RESET << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src.getName()), _grade(src.getGrade())
{
	std::cout << BYELLOW << "Copy constructor called !" << RESET << std::endl;
}

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

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat & rhs )
{
	std::cout << BHYELLOW << "Copy assignment called !" << RESET << std::endl;
	std::cout << BHRED << "You cannot change the name because is a const variable." << RESET << std::endl;
	this->_grade = rhs.getGrade();
	return (*this);
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
