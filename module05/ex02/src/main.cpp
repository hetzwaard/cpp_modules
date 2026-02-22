/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/18 00:34:06 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/22 20:26:44 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "=== ex02: AForm + concrete forms ===" << std::endl;
	try
	{
		Bureaucrat	worker("Worker", 140);
		Bureaucrat	manager("Manager", 40);
		Bureaucrat	boss("Boss", 1);

		ShrubberyCreationForm	shrub("garden");
		RobotomyRequestForm		robot("Bender");
		PresidentialPardonForm	pardon("Arthur Dent");

		std::cout << worker << std::endl;
		std::cout << manager << std::endl;
		std::cout << boss << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;

		worker.executeForm(shrub);
		worker.signForm(shrub);
		worker.executeForm(shrub);
		manager.executeForm(shrub);

		manager.signForm(robot);
		manager.executeForm(robot);

		manager.signForm(pardon);
		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	return (0);
}
