/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/18 00:34:19 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/18 15:09:04 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat(void);
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat(void);
	
	const std::string	&getName(void) const;
	int					getGrade(void) const;
	void					incrementGrade(void);
	void					decrementGrade(void);

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

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif