/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/14 14:14:23 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/16 14:14:34 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main()
{
	std::cout << "=== CREATE OBJECTS ===" << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << "=== GET TYPE ===" << std::endl;

	std::cout << meta->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	std::cout << std::endl;
	std::cout << "=== MAKE SOUND ===" << std::endl;

	meta->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;
	std::cout << "=== CALL DECONSTRUCTORS ===" << std::endl;
	
	delete meta;
	delete dog;
	delete cat;

	std::cout << std::endl;
	std::cout << "=== CREATE WRONG OBJECTS ===" << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << "=== GET TYPE OF WRONG ANIMALS ===" << std::endl;

	std::cout << wrongMeta->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;

	std::cout << std::endl;
	std::cout << "=== MAKE WRONG SOUNDS ===" << std::endl;

	wrongMeta->makeSound();
	wrongCat->makeSound();

	std::cout << std::endl;
	std::cout << "=== CALL DECONSTRUCTOR FOR WRONG ANIMALS ===" << std::endl;

	delete wrongMeta;
	delete wrongCat;

	return (0);
}
