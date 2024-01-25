/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:16:25 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/25 12:06:12 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
// https://cplusplus.com/reference/stack/stack/?kw=stack


template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack< T, Container >
{
	public:
		MutantStack<T, Container>() : std::stack< T, Container >()
		{
		}

		MutantStack<T, Container>( MutantStack<T, Container> const & src )
		{
			if (*this != src )
				*this = src;
		}

		~MutantStack<T, Container>()
		{
		}

		MutantStack<T, Container>	&operator=( MutantStack<T, Container> const & rhs )
		{
			if ( *this != rhs )
				this->c = rhs.c;
			return (*this);
		}

		class InvalidSizeException : public std::exception
		{
		public:
			virtual const char	*what() const throw()
			{
				return ("Invalid size");
			}
		};


		typedef typename Container::iterator		iterator;
		typedef typename Container::const_iterator	const_iterator;

		iterator	begin( void )
		{
			return (this->c.begin());
		}

		void emplace(T const& val)
		{
			this->c.push_back(val);
		}

		void	pop( void )
		{
			if (!this->c.empty())
				return (this->c.pop_back());
			throw InvalidSizeException();
		}

		iterator	end( void )
		{
			return (this->c.end());
		}

		void	swap(MutantStack<T, Container>& x)
		{
			this->c.swap(x.c);
		}
};


#endif
