/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:25:56 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/17 16:57:07 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Colors.hpp"
#include "ostream"
#include "iostream"

Form::Form() : _name("form"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
	std::cout << BGREEN << "Default Form constructor called !" << RESET << std::endl;
}

Form::Form ( std::string name, int signGrade, int executeGrade ) :
	_name(name),
	_isSigned(false),
	_signGrade(signGrade),
	_executeGrade(executeGrade)
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (_signGrade > 150 || _executeGrade > 150)
		throw Form::GradeTooLowException();
	else
		std::cout << BHWHITE << "New form was created ! : " << RESET << *this;
}

Form::Form( const Form & src ) :
	_name(src.getName()),
	_isSigned(src.getIsSigned()),
	_signGrade(src.getSignGrade()),
	_executeGrade(src.getExecuteGrade())
{
	std::cout << BYELLOW << "Copy constructor called !" << RESET << std::endl;
}

Form::~Form()
{
	std::cout << BHRED << this->_name << RESET
	<< BRED << " form was destroyed." << RESET << std::endl;
}

Form&	Form::operator=( const Form & rhs )
{
	(void)rhs;
	std::cout << BHRED << "You cannot do assignment operation because the attributs are constant" << RESET << std::endl;
	return (*this);
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return ("Form Already Signed");
}

std::string	Form::getName( void ) const
{
	return (this->_name);
}
bool	Form::getIsSigned( void ) const
{
	return (this->_isSigned);
}
int	Form::getSignGrade( void ) const
{
	return (this->_signGrade);
}
int	Form::getExecuteGrade( void ) const
{
	return (this->_executeGrade);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

void	Form::beSigned( Bureaucrat const & bureaucrat )
{
	if (this->_isSigned == true)
		return (throw AlreadySignedException());
	if (bureaucrat.getGrade() > this->_signGrade)
		return (throw GradeTooLowException());
	this->_isSigned = true;
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
	o << BHMAG << rhs.getName() << RESET << BHWHITE
	<< ": sign grade : " << RESET << BHYELLOW <<  rhs.getSignGrade() << RESET << BHWHITE
	<< " | execute grade : " << RESET << BHCYAN << rhs.getExecuteGrade() << RESET << BHWHITE
	<< " | " << RESET;
	if (rhs.getIsSigned() == true)
		std::cout << BHGREEN << "signed";
	else
		std::cout << BHRED << "not signed";
	std::cout << RESET << std::endl;
	return (o);
}
