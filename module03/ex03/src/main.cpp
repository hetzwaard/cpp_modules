/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/12 20:33:48 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/13 15:57:22 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diamond("Shiny");

	std::cout << "\n--- diamond actions ---" << std::endl;
	diamond.attack("target");
	diamond.takeDamage(25);
	diamond.beRepaired(10);
	//diamond.status();

	std::cout << "\n--- inherited specials ---" << std::endl;
	diamond.guardGate();
	diamond.highFivesGuys();

	std::cout << "\n--- identity ---" << std::endl;
	diamond.whoAmI();

	return (0);
}
