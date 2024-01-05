/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:31:52 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 13:47:37 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		static int const	_size_inventory = 4;
		AMateria	*_inventory[_size_inventory];
		int			_nb_items;
	public:
		Character( std::string name );
		Character( Character const & src );
		~Character();

		Character	&operator=( Character const & rhs );

		std::string const & getName() const;
		int			getInventorySize() const;
		AMateria*	getMateria(int idx) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif