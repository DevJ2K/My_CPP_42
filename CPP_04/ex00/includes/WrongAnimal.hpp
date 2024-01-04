/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:38:12 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 21:09:18 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal();

		WrongAnimal	&operator=( WrongAnimal const & rhs );

		virtual std::string	getType( void ) const;
		void		makeSound( void ) const;
};

#endif