/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/22 20:19:53 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/22 20:19:55 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "AForm.hpp"
# include <cstdlib>
# include <iostream>

class RobotomyRequestForm : public AForm
{
private:
	const std::string	_target;

protected:
	void				executeAction(void) const;

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm(void);
};

#endif
