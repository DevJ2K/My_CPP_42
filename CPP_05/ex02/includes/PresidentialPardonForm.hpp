/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:18:43 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/18 14:29:02 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;
	static int const	_signGrade = 25;
	static int const	_execGrade = 5;
public:
	PresidentialPardonForm();
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( PresidentialPardonForm const & src );
	~PresidentialPardonForm();

	PresidentialPardonForm	&operator=( PresidentialPardonForm const & rhs );

	std::string	getTarget( void ) const;

	void	customExecute( void ) const;

};

#endif
