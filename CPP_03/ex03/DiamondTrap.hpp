/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:02:07 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/04 10:58:39 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "Colors.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	_name;
public:
	DiamondTrap( std::string name );
	DiamondTrap( DiamondTrap const & src );
	~DiamondTrap();

	DiamondTrap	&operator=( DiamondTrap const & rhs );

	void	whoAmI( void );
	using	ScavTrap::attack; // Pour heriter la fonction attack() de ScavTrap;
};

#endif