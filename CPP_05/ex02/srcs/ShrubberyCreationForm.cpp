/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:19:10 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/18 19:33:12 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Colors.hpp"
#include <iostream>
#include <fstream>

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
	std::string filename = this->getTarget() + "_shrubbery";
	std::string asciiTree =  "  ^  \n / \\ \n/___\\\n";
	std::ofstream ofs(filename.c_str());
	if (!ofs)
	{
		std::cerr << BHRED << "Failed to open the file : " << filename << RESET << std::endl;
		return ;
	}
	ofs << asciiTree;
	std::cout << BHYELLOW << "You're ASCII tree has been succesfully created in : " << RESET
	<< BHGREEN << filename << std::endl;
	std::cout << GREEN << asciiTree << RESET << std::endl;
	ofs.close();
}

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}
