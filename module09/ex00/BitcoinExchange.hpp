/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/05 19:11:19 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/03/09 15:58:01 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <cctype>
# include <sstream>
# include <stdexcept>

class BitcoinExchange
{
private:
	std::string						_dbPath;
	std::map<std::string, double>	_rates;
public:
	BitcoinExchange(const std::string& dbPath = "data.csv");
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	std::string	trim(const std::string &str) const;
	bool		isValidDate(const std::string &date) const;
	bool		parseLine(const std::string &line, std::string &date, std::string &value) const;
	void		loadDatabase();
	double		getRate(const std::string &date) const;
	void		processInput(const std::string &filename);
};

#endif
