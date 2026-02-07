/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/07 16:14:27 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/07 17:00:20 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name) : nameZombie(name) {}

Zombie::~Zombie()
{
	std::cout << nameZombie << " is destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << nameZombie << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
