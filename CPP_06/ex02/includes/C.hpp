/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:07:45 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 17:18:05 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

#include "Base.hpp"
#include <string>

class C : public Base
{
private:
public:
	C();
	~C();
	void displayType( void ) const;
};

#endif
