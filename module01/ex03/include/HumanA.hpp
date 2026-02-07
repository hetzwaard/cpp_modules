/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/07 19:05:00 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/07 19:43:01 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string nameHumanA;
	Weapon&		weapon;

public:
	HumanA(std::string name, Weapon& weapon);
	void	attack(void) const;
};

#endif
