/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:28:43 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/23 16:00:48 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(/* args */)
{
}

Serializer::~Serializer()
{
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	convertToUintptr = reinterpret_cast<uintptr_t>(ptr);
	return (convertToUintptr);
}
