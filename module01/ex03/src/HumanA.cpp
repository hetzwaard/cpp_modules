/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/07 19:26:41 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/07 19:42:54 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : nameHumanA(name), weapon(weapon) {}

void	HumanA::attack(void) const
{
	std::cout << nameHumanA << " attacks with their " << weapon.getType() << std::endl;
}
