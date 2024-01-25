/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:48:41 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/25 13:03:01 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <exception>
#include <list>

class Span
{
private:
	std::list<int>	_list;
	unsigned int	_maxSize;
	Span();
public:
	Span( unsigned int N );
	Span( Span const & src );
	~Span();

	Span	&operator=( Span const & rhs );
	int		operator[]( unsigned int index ) const;

	void	addNumber( int nb );
	void	addNumbers( std::list<int>::const_iterator it, std::list<int>::const_iterator ite);

	std::list<int>	getList( void ) const;
	unsigned int	getMaxSize( void ) const;
	std::size_t	getNbElements( void ) const;

	int	shortestSpan( void ) const;
	int	longestSpan( void ) const;

	class TooManyNumbersException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class OutOfRangeException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class NotEnoughNumbersException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};



};


#endif
