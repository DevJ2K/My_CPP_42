/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:46:58 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 14:16:55 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
	/* data */
public:
	Cat(/* args */);
	Cat( Cat const & src );
	~Cat();

	Cat	&operator=( Cat const & rhs );

	virtual std::string	getType( void ) const;
	virtual void		makeSound( void ) const;
};

#endif
