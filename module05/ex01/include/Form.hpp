/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/18 15:44:21 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/18 16:48:36 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExec;
	bool				_isSigned;
public:
	Form(void);
	Form(const std::string &name, int gradeToSign, int gradeToExec);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form(void);

	const std::string	&getName(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExec(void) const;
	bool				getIsSigned(void) const;
	void				beSigned(const Bureaucrat &bureaucrat);

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
};

std::ostream	&operator<<(std::ostream &os, const Form &form);

#endif
