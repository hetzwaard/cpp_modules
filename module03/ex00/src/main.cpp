/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/12 20:33:48 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/12 21:06:49 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("Alpha");
	ClapTrap	b("Beta");

	a.attack("Beta");
	b.takeDamage(3);
	b.beRepaired(2);

	for (int i = 0; i < 11; i++)
		a.attack("Beta");

	b.takeDamage(20);
	b.beRepaired(5);

	return (0);
}
