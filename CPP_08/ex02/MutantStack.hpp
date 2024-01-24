/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:16:25 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/24 22:46:39 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iterator>
#include <algorithm>
#include <stack>
// https://cplusplus.com/reference/stack/stack/?kw=stack


template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack< T, Container >
{
private:
	std::stack<T>	_stack;
public:
	MutantStack();
	MutantStack( MutantStack const & src );
	~MutantStack();

	typedef typename std::iterator	iterator;

	bool		empty( void ) const
	{
	}
	std::size_t	size( void ) const;
	// T& const	top( void ) const;
	T&			top( void ) const;
	void		push( T const & val );
	void		emplace( T& args ); // Check
	void		pop( void );
	void		swap( std::stack<T> x );

	std::iterator	begin( void ) const;
	std::iterator	end( void ) const;

};
// (constructor)	Construct stack
// empty	Test whether container is empty //OK
// size	Return size //OK
// top	Access next element //OK
// push	Insert element // OK
// emplace	Construct and insert element
// pop	Remove top element
// swap	Swap contents


#endif
