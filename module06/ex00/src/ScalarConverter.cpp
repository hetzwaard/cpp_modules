/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/25 15:07:49 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/25 21:03:54 by mahkilic      ########   odam.nl         */
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

static bool	isNan(double value)
{
	return (value != value);
}

static bool	isInf(double value)
{
	return (value == std::numeric_limits<double>::infinity()
		|| value == -std::numeric_limits<double>::infinity());
}

static bool	isWhole(double value)
{
	if (isNan(value) || isInf(value))
		return (false);
	return (std::floor(value) == value);
}

static void	printImpossible(const char *type)
{
	std::cout << type << ": impossible" << std::endl;
}

static void	printImpossibleAll(void)
{
	printImpossible("char");
	printImpossible("int");
	printImpossible("float");
	printImpossible("double");
}

static bool	isPseudoFloatLiteral(const std::string &input)
{
	return (input == "nanf" || input == "+inff" || input == "-inff");
}

static bool	isPseudoDoubleLiteral(const std::string &input)
{
	return (input == "nan" || input == "+inf" || input == "-inf");
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
	std::size_t	i;

	if (input.empty())
		return (false);
	i = 0;
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
	std::size_t	i;
	int			dots;
	int			digits;

	if (input.empty())
		return (false);
	i = 0;
	if (input[i] == '+' || input[i] == '-')
		++i;
	if (i >= input.length())
		return (false);
	dots = 0;
	digits = 0;
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
	if (isPseudoFloatLiteral(input))
		return (TYPE_PSEUDO_FLOAT);
	if (isPseudoDoubleLiteral(input))
		return (TYPE_PSEUDO_DOUBLE);
	if (isCharLiteral(input))
		return (TYPE_CHAR);
	if (isIntLiteral(input))
		return (TYPE_INT);
	if (isFloatLiteral(input))
		return (TYPE_FLOAT);
	if (isDoubleLiteral(input))
		return (TYPE_DOUBLE);
	return (TYPE_INVALID);
}

static bool	parseInt(const std::string &input, int &out)
{
	char	*end;
	long	value;

	errno = 0;
	value = std::strtol(input.c_str(), &end, 10);
	if (*end != '\0' || errno == ERANGE)
		return (false);
	if (value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
		return (false);
	out = static_cast<int>(value);
	return (true);
}

static bool	parseFloat(const std::string &input, float &out)
{
	std::string	no_suffix;
	char		*end;
	double		value;

	no_suffix = input.substr(0, input.length() - 1);
	errno = 0;
	value = std::strtod(no_suffix.c_str(), &end);
	if (*end != '\0' || errno == ERANGE)
		return (false);
	if (value > static_cast<double>(std::numeric_limits<float>::max())
		|| value < -static_cast<double>(std::numeric_limits<float>::max()))
		return (false);
	out = static_cast<float>(value);
	return (true);
}

static bool	parseDouble(const std::string &input, double &out)
{
	char	*end;
	double	value;

	errno = 0;
	value = std::strtod(input.c_str(), &end);
	if (*end != '\0' || errno == ERANGE)
		return (false);
	out = value;
	return (true);
}

static void	printChar(double value)
{
	char	c;

	if (isNan(value) || isInf(value) || value < 0.0 || value > 127.0)
	{
		printImpossible("char");
		return ;
	}
	c = static_cast<char>(value);
	if (!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

static void	printInt(double value)
{
	if (isNan(value) || isInf(value)
		|| value < static_cast<double>(std::numeric_limits<int>::min())
		|| value > static_cast<double>(std::numeric_limits<int>::max()))
	{
		printImpossible("int");
		return ;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void	printFloat(double value)
{
	std::ios::fmtflags	flags;
	std::streamsize		precision;
	float				f;

	if (isNan(value))
	{
		std::cout << "float: nanf" << std::endl;
		return ;
	}
	if (isInf(value))
	{
		if (value < 0)
			std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: +inff" << std::endl;
		return ;
	}
	if (value > static_cast<double>(std::numeric_limits<float>::max())
		|| value < -static_cast<double>(std::numeric_limits<float>::max()))
	{
		printImpossible("float");
		return ;
	}
	f = static_cast<float>(value);
	flags = std::cout.flags();
	precision = std::cout.precision();
	std::cout << "float: ";
	if (isWhole(static_cast<double>(f)))
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << f << "f" << std::endl;
	std::cout.flags(flags);
	std::cout.precision(precision);
}

static void	printDouble(double value)
{
	std::ios::fmtflags	flags;
	std::streamsize		precision;

	if (isNan(value))
	{
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (isInf(value))
	{
		if (value < 0)
			std::cout << "double: -inf" << std::endl;
		else
			std::cout << "double: +inf" << std::endl;
		return ;
	}
	flags = std::cout.flags();
	precision = std::cout.precision();
	std::cout << "double: ";
	if (isWhole(value))
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
	else
		std::cout << value << std::endl;
	std::cout.flags(flags);
	std::cout.precision(precision);
}

static void	printFromValue(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

static void	printPseudo(const std::string &input, t_type type)
{
	printImpossible("char");
	printImpossible("int");
	if (type == TYPE_PSEUDO_FLOAT)
	{
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.length() - 1)
			<< std::endl;
	}
	else
	{
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
	}
}

void	ScalarConverter::convert(const std::string &input)
{
	t_type	type;
	char	c;
	int		n;
	float	f;
	double	d;

	type = detectType(input);
	if (type == TYPE_INVALID)
		return (printImpossibleAll());
	if (type == TYPE_PSEUDO_FLOAT || type == TYPE_PSEUDO_DOUBLE)
		return (printPseudo(input, type));
	if (type == TYPE_CHAR)
	{
		if (input.length() == 1)
			c = input[0];
		else
			c = input[1];
		return (printFromValue(static_cast<double>(c)));
	}
	if (type == TYPE_INT)
	{
		if (!parseInt(input, n))
			return (printImpossibleAll());
		return (printFromValue(static_cast<double>(n)));
	}
	if (type == TYPE_FLOAT)
	{
		if (!parseFloat(input, f))
			return (printImpossibleAll());
		return (printFromValue(static_cast<double>(f)));
	}
	if (!parseDouble(input, d))
		return (printImpossibleAll());
	printFromValue(d);
}
