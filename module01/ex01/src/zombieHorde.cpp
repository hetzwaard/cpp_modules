/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/07 18:55:29 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/07 18:55:31 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (0);

	Zombie*	horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
		horde[i].setName(name);
	return (horde);
}
