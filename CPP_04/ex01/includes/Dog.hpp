/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:43:13 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 20:25:30 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog();
		Dog( Dog const & src );
		~Dog();

		Dog	&operator=( Dog const & rhs );

		virtual std::string	getType( void ) const;
		virtual void		makeSound( void ) const;
		Brain*	getBrain( void ) const;
};

#endif
