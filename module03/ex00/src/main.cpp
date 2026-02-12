/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/12 20:33:48 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/12 23:01:00 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int	main(void)
{
	ClapTrap	alpha("Alpha");
	ClapTrap	beta("Beta");

	std::cout << "--- initial state ---" << std::endl;
	alpha.status();
	beta.status();

	std::cout << "\n--- alpha attacks beta ---" << std::endl;
	alpha.attack("Beta");
	alpha.status();
	beta.status();

	std::cout << "\n--- beta takes damage and repairs ---" << std::endl;
	beta.takeDamage(4);
	beta.beRepaired(2);
	beta.status();

	std::cout << "\n--- drain alpha energy ---" << std::endl;
	for (int i = 0; i < 10; ++i)
		alpha.attack("Beta");
	alpha.status();

	std::cout << "\n--- kill beta and try actions at 0 HP ---" << std::endl;
	beta.takeDamage(100);
	beta.attack("Alpha");
	beta.beRepaired(1);
	beta.status();

	return (0);
}
