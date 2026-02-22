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
#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "=== ex03: Intern makeForm ===" << std::endl;
	Intern		someRandomIntern;
	Bureaucrat	boss("Boss", 1);
	AForm		*form;

	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form != NULL)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	form = someRandomIntern.makeForm("shrubbery creation", "garden");
	if (form != NULL)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	if (form != NULL)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	form = someRandomIntern.makeForm("unknown form", "Nobody");
	if (form != NULL)
		delete form;

	return (0);
}
