/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/16 17:19:03 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/16 17:44:03 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/ICharacter.hpp"
#include "../include/Character.hpp"
#include "../include/IMateriaSource.hpp"
#include "../include/MateriaSource.hpp"

static void	printSection(const std::string &title)
{
	std::cout << "\n=== " << title << " ===" << std::endl;
}

int	main(void)
{
	printSection("Subject test");
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter		*me = new Character("me");
	AMateria		*tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter		*bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	printSection("Edge tests");
	tmp = src->createMateria("fire");
	if (tmp == 0)
		std::cout << "Unknown type returns 0" << std::endl;
	AMateria *dropped = src->createMateria("ice");
	me->equip(dropped);
	me->unequip(2);
	delete dropped;
	me->use(2, *bob);
	me->use(7, *bob);
	me->unequip(42);

	printSection("Deep copy Character");
	Character	original("original");
	tmp = src->createMateria("cure");
	original.equip(tmp);
	Character	copy(original);
	original.unequip(0);
	delete tmp;
	copy.use(0, *bob);
	Character	assigned("assigned");
	assigned = copy;
	assigned.use(0, *bob);

	delete bob;
	delete me;
	delete src;
	return (0);
}
