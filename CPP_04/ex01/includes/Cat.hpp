/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:46:58 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 10:20:09 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	_brain;
	public:
		Cat();
		Cat( Cat const & src );
		virtual ~Cat();

		Cat	&operator=( Cat const & rhs );

		virtual std::string	getType( void ) const;
		virtual void		makeSound( void ) const;
		Brain*	getBrain( void ) const;
};

#endif
