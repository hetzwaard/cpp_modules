/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/13 12:38:49 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/13 14:01:39 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default")
{
	_hit	= 100;
	_energy	= 50;
	_attack	= 20; 
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_hit	= 100;
	_energy	= 50;
	_attack	= 20;
	std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_hit == 0 || _energy == 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack" << std::endl;
		return ;
	}
	_energy--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now Gate keeper mode." << std::endl;
}
