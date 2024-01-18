/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:09:38 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/18 20:50:44 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const	_name;
	bool	_isSigned;
	int	const _signGrade;
	int	const _executeGrade;
protected:
	virtual void	customExecute( void ) const = 0;

public:
	AForm();
	AForm ( std::string name, int signGrade, int executeGrade );
	AForm( const AForm & src );
	virtual ~AForm();

	AForm	&operator=( const AForm & rhs );

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class AlreadySignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	std::string	getName( void ) const;
	bool	getIsSigned( void ) const;
	int	getSignGrade( void ) const;
	int	getExecuteGrade( void ) const;

	virtual void	beSigned( Bureaucrat const & bureaucrat );

	virtual void	execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif
