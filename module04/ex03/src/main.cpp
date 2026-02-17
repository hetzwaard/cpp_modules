/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/16 17:19:03 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/17 15:44:49 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/ICharacter.hpp"
#include "../include/Character.hpp"
#include "../include/IMateriaSource.hpp"
#include "../include/MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	AMateria* learned;

	learned = new Ice();
	src->learnMateria(learned);
	delete learned;
	learned = new Cure();
	src->learnMateria(learned);
	delete learned;

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}

//int main(void)
//{
//	IMateriaSource *src = new MateriaSource();
//	AMateria		*learned;

//	learned = new Ice();
//	src->learnMateria(learned);
//	delete learned;
//	learned = new Cure();
//	src->learnMateria(learned);
//	delete learned;

//	ICharacter *me = new Character("me");

//	AMateria *skill = src->createMateria("ice");
//	me->equip(skill);

//	skill = src->createMateria("cure");
//	me->equip(skill);

//	ICharacter *you = new Character("you");

//	me->use(0, *you);
//	me->use(1, *you);

//	delete src;
//	delete me;
//	delete you;

//	return (0);
//}
