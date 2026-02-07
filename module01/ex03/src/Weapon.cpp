/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/07 19:15:00 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/07 19:50:18 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type) : typeWeapon(type) {}

const std::string&	Weapon::getType(void) const
{
	return (typeWeapon);
}

void	Weapon::setType(std::string type)
{
	this->typeWeapon = type;
}
