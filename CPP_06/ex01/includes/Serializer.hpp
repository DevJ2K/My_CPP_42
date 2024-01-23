/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:28:41 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 16:36:22 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
#include <stdint.h>
#include "Data.hpp"


class Serializer
{
private:
	Serializer();
public:
	~Serializer();

	static uintptr_t	serialize(Data* ptr);
};

#endif
