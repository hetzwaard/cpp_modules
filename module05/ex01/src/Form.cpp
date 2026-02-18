/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/18 15:53:59 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/18 16:47:51 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(void) : _name("default"), _gradeToSign(150), _gradeToExec(150), _isSigned(false) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _isSigned(false)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec), _isSigned(other._isSigned) {}

Form::~Form(void) {}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

const std::string	&Form::getName(void) const
{
	return (_name);
}

int	Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int	Form::getGradeToExec(void) const
{
	return (_gradeToExec);
}

bool	Form::getIsSigned(void) const
{
	return (_isSigned);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("form grade too high");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("form grade too low");
}

std::ostream	&operator<<(std::ostream &os, const Form &form)
{
	os << form.getName() << ", form sign grade " << form.getGradeToSign()
		<< ", execute grade " << form.getGradeToExec() << ", signed: "
		<< (form.getIsSigned() ? "yes" : "no") << ".";
	return (os);
}
