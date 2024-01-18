/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:18:43 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/18 14:25:35 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;
	static int const	_signGrade = 145;
	static int const	_execGrade = 137;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( ShrubberyCreationForm const & src );
	~ShrubberyCreationForm();

	ShrubberyCreationForm	&operator=( ShrubberyCreationForm const & rhs );

	std::string	getTarget( void ) const;

	void	customExecute( void ) const;

};

#endif
