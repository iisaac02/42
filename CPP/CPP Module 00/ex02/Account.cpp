/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:12:17 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/09/06 11:41:26 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
{
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	std::cout << "index:" << _nbAccounts << ";amount:" << _amount << ";created" << std::endl;
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts()
{
	return _nbAccounts;
}

int	Account::getTotalAmount()
{
	return _totalAmount;
}

int	Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" <<
		_totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_nbDeposits += 1;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit
		<< ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	_amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (_amount - withdrawal < 0)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_displayTimestamp();
	_nbWithdrawals += 1;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" <<
		withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	return (true);
}

int	Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" <<
		_nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t result = time(NULL);

	std::cout << std::setfill('0') << "[" << 1900 + localtime(&result)->tm_year
		<< std::setw(2) << 1 + localtime(&result)->tm_mon
		<< std::setw(2) << localtime(&result)->tm_mday
		<< "_"
		<< std::setw(2) << localtime(&result)->tm_hour
		<< std::setw(2) << localtime(&result)->tm_min
		<< std::setw(2) << localtime(&result)->tm_sec
		<< "] " << std::flush;
}