/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:18:43 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/18 14:28:51 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;
	static int const	_signGrade = 72;
	static int const	_execGrade = 45;
public:
	RobotomyRequestForm();
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( RobotomyRequestForm const & src );
	~RobotomyRequestForm();

	RobotomyRequestForm	&operator=( RobotomyRequestForm const & rhs );

	std::string	getTarget( void ) const;

	void	customExecute( void ) const;

};

#endif
