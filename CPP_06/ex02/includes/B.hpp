/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:07:18 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 17:18:02 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

#include "Base.hpp"
#include <string>

class B : public Base
{
private:
public:
	B();
	~B();
	void displayType( void ) const;
};

#endif
