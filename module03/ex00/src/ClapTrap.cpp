/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/12 20:34:09 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/12 21:13:43 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hit(10), _energy(10), _attack(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hit(10), _energy(10), _attack(0)
{
	std::cout << "ClapTrap constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hit = other._hit;
		_energy = other._energy;
		_attack = other._attack;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_hit == 0 || _energy == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack" << std::endl;
		return ;
	}
	_energy--;

	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
		return ;
	}
	if (amount >= _hit)
		_hit = 0;
	else
		_hit -= amount;

	std::cout << "ClapTrap " << _name << " takes " << amount << " damage, hit points now: " << _hit << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit == 0 || _energy == 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair" << std::endl;
		return ;
	}
	_energy--;
	_hit += amount;

	std::cout << "ClapTrap " << _name << " repairs " << amount << " hit points, hit points now: " << _hit << std::endl;
}

void	ClapTrap::status(void) const
{
	std::cout << "[" << _name << "] HP=" << _hit << ", EP=" << _energy
		<< ", AD=" << _attack << std::endl;
}
