/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:25:58 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/18 20:00:39 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	_name;
	bool	_isSigned;
	int	const _signGrade;
	int	const _executeGrade;
protected:
	virtual void	customExecute( void ) const;

public:
	Form();
	Form ( std::string name, int signGrade, int executeGrade );
	Form( const Form & src );
	~Form();

	Form	&operator=( const Form & rhs );

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

	void	beSigned( Bureaucrat const & bureaucrat );

	virtual void	execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif
