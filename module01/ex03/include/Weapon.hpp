/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/07 19:23:53 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/07 19:32:28 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>

class Weapon
{
private:
	std::string typeWeapon;

public:
	Weapon(std::string type);
	const std::string&	getType(void) const;
	void				setType(std::string type);
};

#endif
