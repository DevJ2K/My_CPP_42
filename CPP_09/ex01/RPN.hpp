/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:10:16 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/27 22:30:03 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <stack>
#include <exception>
#include "CustomInt.hpp"

# define SIZE_LINE 50
# define DISPLAY_PROCESS true

class RPN
{
private:
	std::stack<CustomInt>	_mainStack;
	std::stack<CustomInt>	_calculStack;
public:
	RPN( const char * polish_notation );
	~RPN();

	void	executeCalcul( void );
	void	displayStack( void ) const;

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
	stack_a.pop();
}


#endif
