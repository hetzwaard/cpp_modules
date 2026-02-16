/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/16 17:41:34 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/16 17:33:01 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"

AMateria::AMateria() : _type("") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &other) : _type(other._type) {}

AMateria	&AMateria::operator=(const AMateria &other)
{
	(void)other;
	return (*this);
}

AMateria::~AMateria() {}

std::string const	&AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}
