/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:38:12 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 14:16:03 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal( Animal const & src );
		virtual ~Animal();

		Animal	&operator=( Animal const & rhs );

		virtual std::string	getType( void ) const;
		virtual void		makeSound( void ) const;
};

#endif