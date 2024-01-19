/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:44:04 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/19 09:54:21 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
public:
	Intern();
	Intern( Intern const & src );
	~Intern();

	Intern	&operator=( Intern const & rhs );

	class FormNotExistException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	AForm*	_createRobotomyForm( std::string const & target ) const;
	AForm*	_createShrubberyForm( std::string const & target ) const;
	AForm*	_createPresidentialForm( std::string const & target ) const;


	AForm*	makeForm( std::string formName, std::string target );
};

#endif
