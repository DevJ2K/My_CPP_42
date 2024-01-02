/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:56:05 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/02 19:03:33 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "Colors.hpp"
#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints; // health
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		bool			_check_life_and_energy( std::string action ) const;
	public:
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap	&operator=( ClapTrap const & rhs );

		unsigned int	getHitPoints( void ) const;
		unsigned int	getEnergyPoints( void ) const;
		unsigned int	getAttackDamage( void ) const;
		std::string		getName( void ) const;

		void	displayHealth( void ) const;
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
