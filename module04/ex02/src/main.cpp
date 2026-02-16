/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/14 14:14:23 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/16 16:16:26 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

static void	printSection(const std::string &title)
{
	std::cout << "\n=== " << title << " ===" << std::endl;
}

int	main(void)
{
	const int	size = 6;
	Animal		*animals[size];
	int			i;

	printSection("Polymorphism smoke test");
	const Animal	*j = new Dog();
	const Animal	*k = new Cat();
	std::cout << j->getType() << std::endl;
	std::cout << k->getType() << std::endl;

	printSection("Make sounds");
	j->makeSound();
	k->makeSound();

	printSection("Call Deconstructors");
	delete j;
	delete k;

	printSection("Animal array (half Dog, half Cat)");
	i = 0;
	while (i < size / 2)
	{
		animals[i] = new Dog();
		i++;
	}
	while (i < size)
	{
		animals[i] = new Cat();
		i++;
	}
	i = 0;

	printSection("Get type and make sounds");
	while (i < size)
	{
		std::cout << "[" << i << "] " << animals[i]->getType() << " -> ";
		animals[i]->makeSound();
		i++;
	}
	i = 0;
	printSection("Free all the animals");
	while (i < size)
	{
		delete animals[i];
		i++;
	}

	printSection("Deep copy test (Dog copy constructor)");
	Dog	originalDog;
	originalDog.setIdea(0, "running around");
	Dog	copyDog(originalDog);
	originalDog.setIdea(0, "sleeping");
	std::cout << "originalDog idea[0]: " << originalDog.getIdea(0) << std::endl;
	std::cout << "copyDog idea[0]    : " << copyDog.getIdea(0) << std::endl;

	printSection("Deep copy test (Cat assignment operator)");
	Cat	originalCat;
	originalCat.setIdea(1, "watch birds");
	Cat	assignedCat;
	assignedCat = originalCat;
	originalCat.setIdea(1, "eat fish");
	std::cout << "originalCat idea[1]: " << originalCat.getIdea(1) << std::endl;
	std::cout << "assignedCat idea[1]: " << assignedCat.getIdea(1) << std::endl;

	printSection("Done (call deconstructors)");
	return (0);
}
