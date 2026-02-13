/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/13 15:00:27 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/13 15:00:28 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap("default"),
	FragTrap("default"), _name("default")
{
	_hit = 100;
	_energy = 50;
	_attack = 30;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"),
	ScavTrap(name), FragTrap(name), _name(name)
{
	_hit = 100;
	_energy = 50;
	_attack = 30;
	std::cout << "DiamondTrap constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other),
	ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name
		<< ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
