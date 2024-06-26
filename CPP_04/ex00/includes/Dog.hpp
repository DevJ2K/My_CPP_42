/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:43:13 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 14:25:21 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog( Dog const & src );
	~Dog();

	Dog	&operator=( Dog const & rhs );

	virtual std::string	getType( void ) const;
	virtual void		makeSound( void ) const;
};

#endif
