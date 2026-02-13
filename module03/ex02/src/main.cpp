/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/12 20:33:48 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/13 14:56:48 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int	main(void)
{
	ClapTrap	alpha("Alpha");
	ScavTrap	scavy("Scavy");
	FragTrap	fragy("fragy");

	std::cout << "\n--- alpha attacks scavy ---" << std::endl;
	alpha.attack("Scavy");
	alpha.attack("Scavy");
	alpha.attack("Scavy");
	alpha.attack("Scavy");
	alpha.attack("Scavy");
	scavy.takeDamage(10);
	scavy.guardGate();
	//alpha.status();
	//scavy.status();

	std::cout << "\n--- scavy attacks scavy ---" << std::endl;
	scavy.attack("Alpha");
	scavy.attack("Alpha");
	scavy.attack("Alpha");
	scavy.attack("Alpha");
	scavy.attack("Alpha");
	alpha.takeDamage(50);

	std::cout << "\n--- fragy actions ---" << std::endl;
	fragy.attack("Alpha");
	fragy.takeDamage(15);
	fragy.beRepaired(5);
	fragy.highFivesGuys();

	return (0);
}
