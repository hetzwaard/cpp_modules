/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/16 17:43:35 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/16 18:14:13 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	int	i;

	i = 0;
	while (i < 4)
	{
		_memory[i] = 0;
		i++;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		_memory[i] = 0;
		i++;
	}
	copyMemory(other);
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		clearMemory();
		copyMemory(other);
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	clearMemory();
}

void	MateriaSource::clearMemory()
{
	int	i;

	i = 0;
	while (i < 4)
	{
		delete _memory[i];
		_memory[i] = 0;
		i++;
	}
}

void	MateriaSource::copyMemory(const MateriaSource &other)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (other._memory[i])
			_memory[i] = other._memory[i]->clone();
		else
			_memory[i] = 0;
		i++;
	}
}

void	MateriaSource::learnMateria(AMateria *m)
{
	int	i;

	if (!m)
		return ;
	i = 0;
	while (i < 4)
	{
		if (_memory[i] == 0)
		{
			_memory[i] = m->clone();
			return ;
		}
		i++;
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (_memory[i] && _memory[i]->getType() == type)
			return (_memory[i]->clone());
		i++;
	}
	return (0);
}
