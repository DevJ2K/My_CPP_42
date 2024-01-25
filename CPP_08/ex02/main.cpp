/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:32:04 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/25 12:09:31 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "Colors.hpp"
#include <list>
#include <iostream>
#include <string>

// https://cplusplus.com/reference/stack/stack/?kw=stack

void display_sub_line(std::string title)
{
	size_t line_size = 30;

	std::cout << std::endl;

	for (size_t i = 0; i < (line_size - title.length()) / 2; i++)
		std::cout << BHWHITE << "=" << RESET;

	std::cout << BHCYAN << title << RESET;

	for (size_t i = 0; i < (line_size - title.length()) / 2; i++)
		std::cout << BHWHITE << "=" << RESET;

	std::cout << std::endl;
	std::cout << std::endl;
	return;
}

template <typename T>
void	display_mutant_stack(MutantStack<T> stack)
{
	std::cout << BHWHITE "Size: " << stack.size() << " : [ " << RESET;
	size_t	size_stack = stack.size();
	for (typename MutantStack<T>::iterator it = stack.begin(); it != stack.end(); it++)
	{
		std::cout << BHCYAN << (*it) << RESET;
		if (size_stack > 1)
			std::cout << BHWHITE << " - " << RESET;
		size_stack--;
	}
	std::cout << BHWHITE << " [" << RESET << std::endl;

}

template <typename T>
void	is_empty(MutantStack<T> stack)
{
	std::cout << BHWHITE "Stack is empty ? : " RESET
	<< (stack.empty() ? (BHRED "YES") : (BHGREEN "NO"))
	<< RESET << std::endl;
}

int	main( int argc, char **argv )
{
	display_sub_line("(constructor)");
	MutantStack<std::string> mstack;

	display_sub_line("empty");
	is_empty(mstack);
	try
	{
		mstack.pop();
	}
	catch(MutantStack<std::string>::InvalidSizeException&)
	{
		std::cout << BHRED << "You cannot pop() because your stack is empty !" << RESET << std::endl;
	}
	display_sub_line("size");
	display_mutant_stack(mstack);

	std::cout << BHBLACK "Fill mstack with arguments..." RESET << std::endl;
	for (int i = 0; i < argc; i++)
	{
		std::string str = argv[i];
		mstack.push(str);
	}
	is_empty(mstack);
	display_mutant_stack(mstack);
	display_sub_line("top");
	std::cout << BHWHITE "The top() of the stack is : " RESET BCYAN << mstack.top() << RESET << std::endl;

	std::cout << BHBLACK "Creating new stack..." RESET << std::endl;
	MutantStack<std::string> goodVibesStack;

	display_sub_line("push && emplace");
	goodVibesStack.push("You");
	goodVibesStack.push("are");
	goodVibesStack.emplace("beautiful");
	goodVibesStack.push("!");
	std::cout << BHBLACK "Displaying of goodVibesStack" RESET << std::endl;
	display_mutant_stack(goodVibesStack);

	display_sub_line("swap");
	std::cout << BHBLACK "Swap goodVibesStack and mstack..." RESET << std::endl;
	mstack.swap(goodVibesStack);
	std::cout << std::endl;
	std::cout << BHWHITE "Displaying of goodVibesStack !" RESET << std::endl;
	display_mutant_stack(goodVibesStack);
	std::cout << std::endl;
	std::cout << BHWHITE "Displaying of mstack !" RESET << std::endl;
	display_mutant_stack(mstack);

	display_sub_line("pop");
	mstack.pop();
	mstack.pop();
	display_mutant_stack(mstack);


}

// int	main(void)
// {
// 	display_sub_line("Called all methods");

// 	// MutantStack<std::string> mstack;
// 	// MutantStack<std::string> mstack2;
// 	// mstack.begin();
// 	// mstack.emplace("test");
// 	// mstack.empty();
// 	// mstack.end();
// 	// try
// 	// {
// 	// 	/* code */
// 	// 	mstack.pop();
// 	// 	mstack.pop();
// 	// 	mstack.pop();
// 	// }
// 	// catch(const std::exception& e)
// 	// {
// 	// 	std::cerr << e.what() << '\n';
// 	// }

// 	// mstack.push("test");
// 	// mstack.size();
// 	// mstack.top();
// 	// mstack.swap(mstack);
// 	// mstack2 = mstack;

// 	display_sub_line("List error");
// 	std::list<std::string> list;
// 	std::cout << list.front();
// 	// list.pop_back();
// 	// list.pop_back();
// }
