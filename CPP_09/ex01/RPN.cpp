/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:10:18 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/27 22:34:39 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "Colors.hpp"
#include <iostream>

RPN::RPN( const char * polish_notation )
{
	std::stack<CustomInt>	tmp_stack;

	for (size_t i = 0; polish_notation[i]; i++)
	{
		if (std::isdigit(polish_notation[i])
		|| polish_notation[i] == '+' || polish_notation[i] == '-'
		|| polish_notation[i] == '/' || polish_notation[i] == '*'
		|| polish_notation[i] == ' ')
		{
			if (polish_notation[i] == ' ')
				continue ;
			if (48 <= polish_notation[i] && polish_notation[i] <= 57)
				tmp_stack.push(CustomInt(polish_notation[i] - 48, false));
			else
				tmp_stack.push(CustomInt(polish_notation[i], true));
		}
		else
			throw ValueErrorException();
	}
	size_t size = tmp_stack.size();
	for (size_t i = 0; i < size; i++)
	{
		this->_mainStack.push(tmp_stack.top());
		tmp_stack.pop();
	}
	displayStack();
}

RPN::~RPN()
{}

static void	doOperation(std::stack<CustomInt> & stack_a, std::stack<CustomInt> & stack_b)
{
	if (stack_b.size() < 2)
		throw RPN::ImpossibleCalculErrorException();

	char	sign = stack_a.top().getValue();
	stack_a.pop();

	int nb_1 = stack_b.top().getValue();
	stack_b.pop();
	int nb_2 = stack_b.top().getValue();
	stack_b.pop();
	if (DISPLAY_PROCESS)
	{
		std::cout << BHWHITE "OPERATION => " RESET << BHYELLOW
		<< nb_2 << " " RESET BHMAG << sign << RESET " "
		<< BHYELLOW << nb_1 << RESET << std::endl;
	}
	if (sign == '+')
		return (stack_a.push(CustomInt((nb_1 + nb_2), false)));
	if (sign == '-')
		return (stack_a.push(CustomInt((nb_2 - nb_1), false)));
	if (sign == '/')
	{
		if (nb_2 == 0)
			throw RPN::DivisionByZeroException();
		return (stack_a.push(CustomInt((nb_2 / nb_1), false)));
	}
	if (sign == '*')
		return (stack_a.push(CustomInt((nb_1 * nb_2), false)));
	throw RPN::BadErrorException();

}

void	RPN::executeCalcul( void )
{
	while (this->_mainStack.size() != 1)
	{
		while (!this->_mainStack.top().getIsSign())
		{
			pushTo(this->_mainStack, this->_calculStack);
			if (DISPLAY_PROCESS)
				displayStack();
		}
		doOperation(this->_mainStack, this->_calculStack);
		if (DISPLAY_PROCESS)
			displayStack();
	}
	std::cout << BHGREEN "The result is => " RESET BHMAG << this->_mainStack.top() << RESET << std::endl;
}

void	RPN::displayStack( void ) const
{
	std::cout << BHWHITE;
	for (size_t i = 0; i < SIZE_LINE; i++)
		std::cout << "=";
	std::cout << RESET << std::endl;

	std::stack<CustomInt>	copyStack;
	std::stack<CustomInt>	tmpStack;

	copyStack = this->_mainStack;
	tmpStack = reverseStack(copyStack);
	std::cout << BHWHITE "MAIN_STACK   = [" RESET;
	for (size_t i = copyStack.size(); i > 0; i--)
	{
		std::cout << BHCYAN "'" << tmpStack.top() << "'" RESET;
		tmpStack.pop();
		if (tmpStack.size() > 0)
			std::cout << BHWHITE " " RESET;
	}
	std::cout << BHWHITE "[" RESET << std::endl;

	copyStack = this->_calculStack;
	tmpStack = reverseStack(copyStack);
	std::cout << BHWHITE "CALCUL_STACK = [" RESET;
	for (size_t i = copyStack.size(); i > 0; i--)
	{
		std::cout << BHCYAN "'" << tmpStack.top() << "'" RESET;
		tmpStack.pop();
		if (tmpStack.size() > 0)
			std::cout << BHWHITE " " RESET;
	}
	std::cout << BHWHITE "[" RESET << std::endl;

	std::cout << BHWHITE;
	for (size_t i = 0; i < SIZE_LINE; i++)
		std::cout << "=";
	std::cout << RESET << std::endl << std::endl;
}

const char	*RPN::ValueErrorException::what() const throw()
{
	return ("Value Error");
}
const char	*RPN::ImpossibleCalculErrorException::what() const throw()
{
	return ("Impossible Calcul");
}

const char	*RPN::DivisionByZeroException::what() const throw()
{
	return ("Division By Zero");
}

const char	*RPN::BadErrorException::what() const throw()
{
	return ("Bad Error");
}
