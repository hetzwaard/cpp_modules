/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/16 14:57:14 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/16 15:00:59 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain()
{
	int	i;

	i = 0;
	while (i < 100)
	{
		ideas[i] = "";
		i++;
	}
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain	&Brain::operator=(const Brain &other)
{
	int	i;

	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		i = 0;
		while (i < 100)
		{
			ideas[i] = other.ideas[i];
			i++;
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0 || index >= 100)
		return ;
	ideas[index] = idea;
}

std::string const	&Brain::getIdea(int index) const
{
	static const std::string	empty = "";

	if (index < 0 || index >= 100)
		return (empty);
	return (ideas[index]);
}
