/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/22 20:19:33 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/22 20:19:34 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "AForm.hpp"
# include <iostream>

class PresidentialPardonForm : public AForm
{
private:
	const std::string	_target;

protected:
	void				executeAction(void) const;

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm(void);
};

#endif
