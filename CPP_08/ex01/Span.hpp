/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:48:41 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/24 16:55:07 by tajavon          ###   ########.fr       */
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
	unsigned int	_nbElements;
	unsigned int	_size;
	Span();
public:
	Span( unsigned int N );
	Span( Span const & src );
	~Span();

	Span	&operator=( Span const & rhs );
	int		operator[]( unsigned int index ) const;

	void	addNumber( int nb );
	unsigned int	getSize( void ) const;
	unsigned int	getNbElements( void ) const;

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
