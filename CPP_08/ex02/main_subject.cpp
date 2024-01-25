/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_subject.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:16:03 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/25 12:13:06 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "Colors.hpp"
#include <list>
#include <deque>
#include <iostream>

static void display_sub_line(std::string title)
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


int main()
{

	display_sub_line("MutantStack");

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	// mstack.emplace(42);
	// [...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);


	display_sub_line("std::list");

	std::list<int> stdlist;
	stdlist.push_back(5);
	stdlist.push_back(17);
	std::cout << stdlist.back() << std::endl;
	stdlist.pop_back();
	std::cout << stdlist.size() << std::endl;
	stdlist.push_back(3);
	stdlist.push_back(5);
	stdlist.push_back(737);
	// C++11 Required
	// stdlist.emplace_back(42);
	//[...]
	stdlist.push_back(0);
	std::list<int>::iterator l_it = stdlist.begin();
	std::list<int>::iterator l_ite = stdlist.end();
	++l_it;
	--l_it;
	while (l_it != l_ite)
	{
	std::cout << *l_it << std::endl;
	++l_it;
	}
	std::list<int> l(stdlist);

	display_sub_line("std::deque");

	std::deque<int> stddeque;
	stddeque.push_back(5);
	stddeque.push_back(17);
	std::cout << stddeque.back() << std::endl;
	stddeque.pop_back();
	std::cout << stddeque.size() << std::endl;
	stddeque.push_back(3);
	stddeque.push_back(5);
	stddeque.push_back(737);
	// stddeque.emplace_back(42);
	//[...]
	stddeque.push_back(0);
	std::deque<int>::iterator d_it = stddeque.begin();
	std::deque<int>::iterator d_ite = stddeque.end();
	++d_it;
	--d_it;
	while (d_it != d_ite)
	{
	std::cout << *d_it << std::endl;
	++d_it;
	}
	std::deque<int> d(stddeque);
	return 0;
}
