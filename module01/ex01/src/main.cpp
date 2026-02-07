/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/07 18:55:25 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/07 19:10:53 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main(void)
{
	int		count = 5;
	Zombie*	horde = zombieHorde(count, "ArghHgra");

	if (!horde)
		return (1);

	for (int i = 0; i < count; ++i)
		horde[i].announce();

	delete [] horde;
	return (0);
}
