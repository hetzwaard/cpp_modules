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

#include <iostream>
#include <ctime>
#include "../include/Account.hpp"

int Account::	_nbAccounts = 0;
int Account::	_totalAmount = 0;
int Account::	_totalNbDeposits = 0;
int Account::	_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	std::time_t	now	=	std::time(0);
	std::tm		*info	=	std::localtime(&now);

	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", info);

	std::cout << buffer;
}

Account::Account(int initial_deposit)
{
	_accountIndex	 = _nbAccounts;
	_nbAccounts		 = _nbAccounts + 1;

	_amount			 = initial_deposit;
	_totalAmount	 = initial_deposit + _totalAmount;

	_nbDeposits		 = 0;
	_nbWithdrawals	 = 0; 

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

int	Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();

	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	p = _amount;
	_amount = _amount + deposit;
	_totalAmount = _totalAmount + deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	Account::_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p = _amount;

	if (withdrawal > _amount)
	{
		Account::_displayTimestamp();

		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << p << ";";
		std::cout << "withdrawal:refused" << std::endl;

		return (false);
	}

	_amount = _amount - withdrawal;
	_totalAmount = _totalAmount - withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	Account::_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;

	return (true);
}
