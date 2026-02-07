/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/07 18:55:09 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/07 18:59:20 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie() : nameZombie("") {}

Zombie::Zombie(std::string name) : nameZombie(name) {}

Zombie::~Zombie()
{
	std::cout << nameZombie << " is destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << nameZombie << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->nameZombie = name;
}
