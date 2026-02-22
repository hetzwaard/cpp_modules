/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/22 21:56:22 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/22 21:56:23 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include "AForm.hpp"
# include <string>

class Intern
{
private:
	typedef AForm	*(*FormCreator)(const std::string &target);

	static AForm	*createShrubberyForm(const std::string &target);
	static AForm	*createRobotomyForm(const std::string &target);
	static AForm	*createPresidentialForm(const std::string &target);

public:
	Intern(void);
	Intern(const Intern &other);
	Intern	&operator=(const Intern &other);
	~Intern(void);

	AForm	*makeForm(const std::string &formName, const std::string &target) const;
};

#endif
