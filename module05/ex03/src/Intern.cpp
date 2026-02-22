/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/22 21:56:05 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/22 21:57:00 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

#include <iostream>

Intern::Intern(void) {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern(void) {}

AForm	*Intern::createShrubberyForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createRobotomyForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresidentialForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target) const
{
	const std::string	formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	FormCreator	creators[3] = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (creators[i](target));
		}
	}
	std::cout << "Intern couldn't create " << formName << std::endl;
	return (NULL);
}
