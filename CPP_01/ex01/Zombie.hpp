/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:08:13 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/29 16:32:23 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
#include <string>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie();
		~Zombie();

		void	announce( void );
		void	setName( std::string name );
};

#endif
