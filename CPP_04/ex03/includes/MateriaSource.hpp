/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:23:39 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/05 13:42:45 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static int const	_size_inventory = 4;
	AMateria	*_inventory[_size_inventory];
	int			_nb_items;
public:
	MateriaSource();
	MateriaSource( MateriaSource const & src );
	~MateriaSource();

	MateriaSource	&operator=( MateriaSource const & rhs );

	AMateria*	getMateria(int idx) const;

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);

};

#endif