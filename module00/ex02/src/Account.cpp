/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/06 14:42:25 by mahkilic      #+#    #+#                 */
/*   Updated: 2026/02/06 14:42:25 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts)
	, _amount(initial_deposit)
	, _nbDeposits(0)
	, _nbWithdrawals(0)
{
	_nbAccounts += 1;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				 << ";amount:" << _amount
				 << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				 << ";amount:" << _amount
				 << ";closed" << std::endl;
}

int		Account::getNbAccounts()
{
	return (_nbAccounts);
}

int		Account::getTotalAmount()
{
	return (_totalAmount);
}

int		Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
				 << ";total:" << getTotalAmount()
				 << ";deposits:" << getNbDeposits()
				 << ";withdrawals:" << getNbWithdrawals()
				 << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	previousAmount = _amount;

	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	_amount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				 << ";p_amount:" << previousAmount
				 << ";deposit:" << deposit
				 << ";amount:" << _amount
				 << ";nb_deposits:" << _nbDeposits
				 << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	previousAmount = _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				 << ";p_amount:" << previousAmount
				 << ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	std::cout << withdrawal
				 << ";amount:" << _amount
				 << ";nb_withdrawals:" << _nbWithdrawals
				 << std::endl;
	return (true);
}

int		Account::checkAmount() const
{
	return (_amount);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				 << ";amount:" << _amount
				 << ";deposits:" << _nbDeposits
				 << ";withdrawals:" << _nbWithdrawals
				 << std::endl;
}

void	Account::_displayTimestamp()
{
	std::time_t	current = std::time(NULL);
	std::tm		*tm = std::localtime(&current);
	char		buffer[32];

	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", tm);
	std::cout << buffer;
}
