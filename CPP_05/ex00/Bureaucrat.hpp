/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:57:24 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/17 13:16:53 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATE_HPP
# define BUREAUCRATE_HPP

#include <string>
#include <ostream>
#include <iostream>

class Bureaucrat
{
private:
	std::string const	_name;
	int	_grade;
public:
	Bureaucrat( std::string name, int grade );
	~Bureaucrat();

	std::string	getName( void ) const;
	int			getGrade( void ) const;

	void	increaseGrade( void );
	void	decreaseGrade( void );

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

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);


#endif
