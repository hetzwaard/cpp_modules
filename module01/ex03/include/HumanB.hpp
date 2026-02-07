/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/07 19:27:49 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/07 19:43:27 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string nameHumanB;
	Weapon*		weapon;

public:
	HumanB(std::string name);
	void	setWeapon(Weapon& weapon);
	void	attack(void) const;
};

#endif
