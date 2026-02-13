/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/13 14:42:12 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/13 14:55:16 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default")
{
	_hit	= 100;
	_energy	= 100;
	_attack	= 30; 
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hit	= 100;
	_energy	= 100;
	_attack	= 30;
	std::cout << "FragTrap constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << _name << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (_hit == 0 || _energy == 0)
	{
		std::cout << "FragTrap " << _name << " can't attack" << std::endl;
		return ;
	}
	_energy--;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}
