/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/22 21:56:17 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/22 21:56:19 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

protected:
	virtual void		executeAction(void) const = 0;

public:
	AForm(void);
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm(void);

	const std::string	&getName(void) const;
	bool				getIsSigned(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExecute(void) const;

	void				beSigned(const Bureaucrat &bureaucrat);
	void				execute(const Bureaucrat &executor) const;

	class GradeTooHighException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const AForm &form);

#endif
