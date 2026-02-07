/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/07 16:14:14 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/07 17:01:48 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main(void)
{
	randomChump("Argh");

	Zombie*	zombie = newZombie("Hgra");
	zombie->announce();
	delete zombie;
	return (0);
}
