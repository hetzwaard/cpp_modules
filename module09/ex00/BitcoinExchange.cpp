/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/05 19:20:02 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/09 17:54:20 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &dbPath) : _dbPath(dbPath) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _dbPath(other._dbPath), _rates(other._rates) {}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_dbPath = other._dbPath;
		_rates = other._rates;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

std::string	BitcoinExchange::trim(const std::string &str) const
{
	std::size_t	start = 0;

	while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start])))
		start++;

	std::size_t	end = str.size();
	while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
		end--;

	return (str.substr(start, end - start));
}

bool	BitcoinExchange::parseLine(const std::string &line, std::string &date, std::string &value) const
{
	std::size_t	pipePos = line.find('|');

	if (pipePos == std::string::npos)
		return (false);

	date = trim(line.substr(0, pipePos));
	value = trim(line.substr(pipePos + 1));

	return (true);
}

void	BitcoinExchange::loadDatabase()
{
	std::ifstream	file(_dbPath);

	if (!file.is_open())
		throw std::runtime_error("could not open database file");

	std::string	line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::size_t	comma = line.find(',');
		if (comma == std::string::npos)
			continue;

		std::string	date = line.substr(0, comma);
		double		rate = std::stod(line.substr(comma + 1));
		_rates[date] = rate;
	}
}

bool		BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10)
		return (false);

	if (date[4] != '-' || date[7] != '-')
		return (false);

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return (false);
	}

	int	year = std::stoi(date.substr(0, 4));
	int	month = std::stoi(date.substr(5, 2));
	int	day = std::stoi(date.substr(8, 2));

	if (year < 2009)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1)
		return (false);

	int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	bool	isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (month == 2 && isLeap)
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		return (false);

	return (true);
}

double	BitcoinExchange::getRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator	it = _rates.lower_bound(date);

	if (it != _rates.end() && it->first == date)
		return (it->second);

	if (it == _rates.begin())
		throw std::runtime_error("date too early for database");

	--it;

	return (it->second);
}

void	BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream	file(filename);

	if (!file.is_open())
		throw std::runtime_error("could not open file.");

	std::string	line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::string	date, valueStr;

		if (!parseLine(line, date, valueStr))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		double	value;
		try
		{
			value = std::stod(valueStr);
		}
		catch (...)
		{
			std::cerr << "Error: bad input => " << valueStr << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		try
		{
			double	rate = getRate(date);
			std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}
