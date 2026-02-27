/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/25 15:07:49 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/27 17:11:11 by mahkilic      ########   odam.nl         */
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

static bool isWhole(double x)
{
	return (std::floor(x) == x);
}

static bool	isNan(double d)
{
	return (d != d);
}

static bool	isInf(double d)
{
	return (d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity());
}

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

static char	parseChar(const std::string &input)
{
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		return (input[1]);
	return (input[0]);
}

static void	printChar(char c)
{
	if (!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

static void printCharFromInt(int n)
{
	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(n)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
}

static void	printCharFromDouble(double c)
{
	if (isNan(c) || isInf(c) || c < 0.0 || c > 127.0)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(static_cast<int>(c))))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
}

static int parseInt(const std::string &input)
{
	char	*ptr;
	long	value;

	errno = 0;
	ptr = NULL;

	value = std::strtol(input.c_str(), &ptr, 10);
	if (ptr == input.c_str() || *ptr != '\0' || errno == ERANGE
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
		throw std::overflow_error("invalid int literal");
	return (static_cast<int>(value));
}

static void	printInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

static void	printIntFromDouble(double n)
{
	if (isNan(n) || isInf(n)
		|| n < std::numeric_limits<int>::min()
		|| n > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;
}

static float	parseFloat(const std::string &input)
{
	char		*ptr;
	double		value;
	std::string	nos;

	nos = input.substr(0, input.length() - 1);
	errno = 0;
	ptr = NULL;

	value = std::strtod(nos.c_str(), &ptr);
	if (ptr == nos.c_str() || *ptr != '\0' || errno == ERANGE
		|| value > std::numeric_limits<float>::max()
		|| value < -std::numeric_limits<float>::max())
		throw std::overflow_error("invalid float literal");
	return (static_cast<float>(value));
}

static void	printFloat(float f)
{
	std::ios::fmtflags	oldFlags = std::cout.flags();
	std::streamsize		oldPrec = std::cout.precision();

	std::cout << "float: ";
	if (isNan(f))
		std::cout << "nanf";
	else if (isInf(f))
		std::cout << (f > 0 ? "+inff" : "-inff");
	else
	{
		if (isWhole(static_cast<double>(f)))
			std::cout << std::fixed << std::setprecision(1);
		std::cout << f << "f";
	}
	std::cout << std::endl;
	std::cout.flags(oldFlags);
	std::cout.precision(oldPrec);
}

static double	parseDouble(const std::string &input)
{
	char	*ptr;
	double	value;

	errno = 0;
	ptr = NULL;

	value = std::strtod(input.c_str(), &ptr);
	if (ptr == input.c_str() || *ptr != '\0' || errno == ERANGE)
		throw std::overflow_error("invalid double literal");
	return (value);
}

static void	printDouble(double d)
{
	std::ios::fmtflags	oldFlags = std::cout.flags();
	std::streamsize		oldPrec = std::cout.precision();

	std::cout << "double: ";
	if (isNan(d))
		std::cout << "nan";
	else if (isInf(d))
		std::cout << (d < 0 ? "-inf" : "+inf");
	else
	{
		if (isWhole(d))
			std::cout << std::fixed << std::setprecision(1);
		std::cout << d;
	}
	std::cout << std::endl;
	std::cout.flags(oldFlags);
	std::cout.precision(oldPrec);
}

static void	printPseudoFloat(const std::string &input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << input << std::endl;

	if (input == "nanf")
		std::cout << "double: nan" << std::endl;
	else if (input == "+inff")
		std::cout << "double: +inf" << std::endl;
	else
		std::cout << "double: -inf" << std::endl;
}

static void	printPseudoDouble(const std::string &input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (input == "nan")
		std::cout << "float: nanf" << std::endl;
	else if (input == "+inf")
		std::cout << "float: +inff" << std::endl;
	else
		std::cout << "float: -inff" << std::endl;
	std::cout << "double: " << input << std::endl;
}

void	ScalarConverter::convert(const std::string &input)
{
	t_type		type = detectType(input);

	switch (type)
	{
		case TYPE_INVALID:
		{
			printImpossibleAll();
			break ;
		}
		case TYPE_CHAR:
		{
			char c = parseChar(input);
			printChar(c);
			printInt(static_cast<int>(c));
			printFloat(static_cast<float>(c));
			printDouble(static_cast<double>(c));
			break ;
		}
		case TYPE_INT:
		{
			try
			{
				int n = parseInt(input);
				printCharFromInt(n);
				printInt(n);
				printFloat(static_cast<float>(n));
				printDouble(static_cast<double>(n));
				break ;
			}
			catch (...)
			{
				printImpossibleAll();
				break ;
			}
		}
		case TYPE_FLOAT:
		{
			try
			{
				float f = parseFloat(input);
				printCharFromDouble(static_cast<double>(f));
				printIntFromDouble(static_cast<double>(f));
				printFloat(f);
				printDouble(static_cast<double>(f));
				break ;
			}
			catch (...)
			{
				printImpossibleAll();
				break ;
			}
		}
		case TYPE_DOUBLE:
		{
			try
			{
				double d = parseDouble(input);
				printCharFromDouble(d);
				printIntFromDouble(d);
				printFloat(static_cast<float>(d));
				printDouble(d);
				break ;
			}
			catch (...)
			{
				printImpossibleAll();
				break ;
			}
		}
		case TYPE_PSEUDO_FLOAT:
		{
			printPseudoFloat(input);
			break ;
		}
		case TYPE_PSEUDO_DOUBLE:
		{
			printPseudoDouble(input);
			break ;
		}
		default:
			break ;
	}
}
