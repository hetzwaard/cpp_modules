/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/16 17:43:12 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/16 17:43:12 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

Character::Character() : _name("default")
{
	int	i;

	i = 0;
	while (i < 4)
	{
		_inventory[i] = 0;
		i++;
	}
}

Character::Character(const std::string &name) : _name(name)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		_inventory[i] = 0;
		i++;
	}
}

Character::Character(const Character &other) : _name(other._name)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		_inventory[i] = 0;
		i++;
	}
	copyInventory(other);
}

Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		clearInventory();
		copyInventory(other);
	}
	return (*this);
}

Character::~Character()
{
	clearInventory();
}

void	Character::clearInventory()
{
	int	i;

	i = 0;
	while (i < 4)
	{
		delete _inventory[i];
		_inventory[i] = 0;
		i++;
	}
}

void	Character::copyInventory(const Character &other)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
		i++;
	}
}

std::string const	&Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	int	i;

	if (!m)
		return ;
	i = 0;
	while (i < 4)
	{
		if (_inventory[i] == 0)
		{
			_inventory[i] = m;
			return ;
		}
		i++;
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	_inventory[idx] = 0;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		return ;
	if (_inventory[idx] == 0)
		return ;
	_inventory[idx]->use(target);
}
