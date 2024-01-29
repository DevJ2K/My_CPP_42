/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:10:16 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/29 09:41:05 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <stack>
#include <exception>
#include <iostream>
#include "Colors.hpp"
#include "CustomInt.hpp"

# define SIZE_LINE 50
# define DISPLAY_PROCESS true

class RPN
{
private:
	std::stack<CustomInt>	_mainStack;
	std::stack<CustomInt>	_calculStack;
	RPN();
public:
	RPN( RPN const & src );
	RPN( const char * polish_notation );
	~RPN();

	RPN	&operator=( RPN const & rhs );

	void	executeCalcul( void );
	void	displayStack( void ) const;

	std::stack<CustomInt>	getMainStack( void ) const;
	std::stack<CustomInt>	getCalculStack( void ) const;

	class ValueErrorException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class ImpossibleCalculErrorException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class DivisionByZeroException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class BadErrorException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
};

template <typename T>
std::stack<T>	reverseStack( std::stack<T> stack )
{
	std::stack<T>	reverse_stack;
	size_t size = stack.size();
	for (size_t i = 0; i < size; i++)
	{
		reverse_stack.push(stack.top());
		stack.pop();
	}
	return (reverse_stack);
}

template <typename T>
void	pushTo(std::stack<T> & stack_a, std::stack<T> & stack_b)
{
	if (stack_a.size() == 0)
		throw RPN::ImpossibleCalculErrorException();
	stack_b.push(stack_a.top());
	if (DISPLAY_PROCESS)
	{
		std::cout << BHWHITE "PUSH => " RESET << BHBLUE
		<< stack_a.top() << RESET << std::endl << std::endl;
	}
	stack_a.pop();
}


#endif
