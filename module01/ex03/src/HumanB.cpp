/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/07 19:25:27 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/07 19:50:16 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name) : nameHumanB(name), weapon(0) {}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void) const
{
	if (!weapon)
		return ;
	std::cout << nameHumanB << " attacks with their " << weapon->getType() << std::endl;
}
