/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:25:56 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/18 14:15:19 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Colors.hpp"
#include "ostream"
#include "iostream"

AForm::AForm() : _name("form"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
}

AForm::AForm ( std::string name, int signGrade, int executeGrade ) :
	_name(name),
	_isSigned(false),
	_signGrade(signGrade),
	_executeGrade(executeGrade)
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (_signGrade > 150 || _executeGrade > 150)
		throw AForm::GradeTooLowException();
	else
		std::cout << BHWHITE << "New form was created ! : " << RESET << *this;
}

AForm::AForm( const AForm & src ) :
	_name(src.getName()),
	_isSigned(src.getIsSigned()),
	_signGrade(src.getSignGrade()),
	_executeGrade(src.getExecuteGrade())
{
	std::cout << BYELLOW << "Copy constructor called !" << RESET << std::endl;
}

AForm::~AForm()
{
	std::cout << BHRED << this->_name << RESET
	<< BRED << " form was destroyed." << RESET << std::endl;
}

AForm&	AForm::operator=( const AForm & rhs )
{
	(void)rhs;
	std::cout << BHRED << "You cannot do assignment operation because the attributs are constant" << RESET << std::endl;
	return (*this);
}

const char*	AForm::AlreadySignedException::what() const throw()
{
	return ("Form Already Signed");
}

const char*	AForm::NotSignedException::what() const throw()
{
	return ("Not Signed");
}

std::string	AForm::getName( void ) const
{
	return (this->_name);
}
bool	AForm::getIsSigned( void ) const
{
	return (this->_isSigned);
}
int	AForm::getSignGrade( void ) const
{
	return (this->_signGrade);
}
int	AForm::getExecuteGrade( void ) const
{
	return (this->_executeGrade);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

void	AForm::beSigned( Bureaucrat const & bureaucrat )
{
	if (this->_isSigned == true)
		return (throw AlreadySignedException());
	if (bureaucrat.getGrade() > this->_signGrade)
		return (throw GradeTooLowException());
	this->_isSigned = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->_isSigned == false)
		return (throw NotSignedException());
	if (executor.getGrade() > this->_signGrade || executor.getGrade() > this->_executeGrade)
		return (throw GradeTooLowException());
	this->customExecute();
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs)
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
