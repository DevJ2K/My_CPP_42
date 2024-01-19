/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:44:46 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/19 10:22:40 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Colors.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <map>
#include <list>
#include <iostream>

Intern::Intern()
{
	std::cout << BHGREEN << "Default constructor of intern called !" << RESET << std::endl;
}
Intern::Intern( Intern const & src )
{
	std::cout << BHYELLOW << "Copy constructor of intern called !" << RESET << std::endl;
	*this = src;
}
Intern::~Intern()
{
	std::cout << BHRED << "Destructor of intern called !" << RESET << std::endl;
}

Intern	&Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	std::cout << BHYELLOW << "Intern Class has no member..." << RESET << std::endl;
	return (*this);
}

const char *Intern::FormNotExistException::what() const throw()
{
	return ("Form Not Exist");
}

AForm*	Intern::_createRobotomyForm( std::string const & target ) const
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::_createShrubberyForm( std::string const & target ) const
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::_createPresidentialForm( std::string const & target ) const
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm( std::string formName, std::string target )
{
	std::map<std::string, AForm* (Intern::*)( std::string const & target ) const> formMap;
	formMap["robotomy request"] = &Intern::_createRobotomyForm;
	formMap["shrubbery creation"] = &Intern::_createShrubberyForm;
	formMap["presidential pardon"] = &Intern::_createPresidentialForm;
	if (formMap.find(formName) != formMap.end())
	{
		AForm	*newForm = (this->*formMap[formName])(target);
		return (newForm);
	}
	throw FormNotExistException();
	return (NULL);
}

// AForm*	Intern::makeForm( std::string formName, std::string target )
// {
// 	std::string valideList[3] = {
// 		"robotomy request",
// 		"shrubbery creation",
// 		"presidential pardon"
// 	};
// 	int	index = -1;
// 	for (size_t i = 0; i < 3; i++)
// 	{
// 		if (valideList[i] == formName)
// 			index = i;
// 	}
// 	switch (index)
// 	{
// 	case 0:
// 		return (new RobotomyRequestForm(target));
// 	case 1:
// 		return (new ShrubberyCreationForm(target));
// 	case 2:
// 		return (new PresidentialPardonForm(target));
// 	default:
// 		throw FormNotExistException();
// 		return (NULL);
// 	}
// }
