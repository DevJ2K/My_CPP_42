/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:20:30 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/29 18:26:51 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(/* args */);
		~Weapon();

	std::string const & getType( void );
	void	setType( std::string type );
};

