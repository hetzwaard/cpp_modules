/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/25 15:07:49 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/26 19:32:56 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

/*

According to subject, we've got to handle these for fun.

	nanf -> float NaN
	nan -> double NaN
	+inff -> float +infinity
	+inf -> double +infinity

*/

static bool	isPseudoFloatLiteral(const std::string &input)
{
	return (input == "nanf" || input == "+inff" || input == "-inff");
}

static bool	isPseudoDoubleLiteral(const std::string &input)
{
	return (input == "nan" || input == "+inf" || input == "-inf");
}

static void	printImpossibleAll(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static bool	isCharLiteral(const std::string &input)
{
	if (input.length() == 1 && !std::isdigit(static_cast<unsigned char>(input[0])))
		return (true);
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		return (true);
	return (false);
}

static bool	isIntLiteral(const std::string &input)
{
	std::size_t	i = 0;

	if (input.empty())
		return (false);
	if (input[i] == '+' || input[i] == '-')
		++i;
	if (i >= input.length())
		return (false);
	while (i < input.length())
	{
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return (false);
		++i;
	}
	return (true);
}

static bool	isDecimalLiteral(const std::string &input)
{
	std::size_t	i = 0;
	int			dots = 0;
	int			digits = 0;

	if (input.empty())
		return (false);
	if (input[i] == '+' || input[i] == '-')
		++i;
	if (i >= input.length())
		return (false);
	while (i < input.length())
	{
		if (std::isdigit(static_cast<unsigned char>(input[i])))
			digits++;
		else if (input[i] == '.')
			dots++;
		else
			return (false);
		if (dots > 1)
			return (false);
		++i;
	}
	return (digits > 0 && dots == 1);
}

static bool	isFloatLiteral(const std::string &input)
{
	if (input.length() < 2 || input[input.length() - 1] != 'f')
		return (false);
	return (isDecimalLiteral(input.substr(0, input.length() - 1)));
}

static bool	isDoubleLiteral(const std::string &input)
{
	return (isDecimalLiteral(input));
}

static t_type	detectType(const std::string &input)
{
	if (isCharLiteral(input))
		return (TYPE_CHAR);
	if (isIntLiteral(input))
		return (TYPE_INT);
	if (isPseudoFloatLiteral(input))
		return (TYPE_PSEUDO_FLOAT);
	if (isPseudoDoubleLiteral(input))
		return (TYPE_PSEUDO_DOUBLE);
	if (isFloatLiteral(input))
		return (TYPE_FLOAT);
	if (isDoubleLiteral(input))
		return (TYPE_DOUBLE);
	return (TYPE_INVALID);
}

static void	printChar(const std::string &input)
{
	std::cout << "char: " << input << std::endl;
}

static void	printImpossibleChar(void)
{
	std::cout << "char: impossible" << std::endl;
}

static void	printInt(const std::string &input)
{
	std::cout << "int: " << input << std::endl;
}

static void	printImpossibleInt(void)
{
	std::cout << "int: impossible" << std::endl;
}

static void	printFloat(const std::string &input)
{
	std::cout << "float: " << input << std::endl;
}

static void	printDouble(const std::string &input)
{
	std::cout << "double: " << input << std::endl;
}

static void	printPseudoFloat(const std::string &input)
{
	std::cout << "float: " << input << std::endl;
}

static void	printPseudoDouble(const std::string &input)
{
	std::cout << "double: " << input << std::endl;
}

void	ScalarConverter::convert(const std::string &input)
{
	t_type		type = detectType(input);

	if (type == TYPE_INVALID)
	{
		printImpossibleAll();
		return ;
	}
	if (type == TYPE_CHAR)
		printChar(input);
	else
		printImpossibleChar();
	if (type == TYPE_INT)
		printInt(input);
	else
		printImpossibleInt();
	switch (type)
	{
		case TYPE_FLOAT:
			printFloat(input);
		case TYPE_DOUBLE:
			printDouble(input);
		case TYPE_PSEUDO_FLOAT:
			printPseudoFloat(input);
		case TYPE_PSEUDO_DOUBLE:
			printPseudoDouble(input);
		default:
			break ;
	}
}
