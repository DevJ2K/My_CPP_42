/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:39:35 by tajavon           #+#    #+#             */
/*   Updated: 2023/12/29 11:18:24 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <time.h>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _nbDeposits(0), _nbWithdrawals(0)
{

	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount += initial_deposit;
	Account::_totalAmount += initial_deposit;


	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<";";
	std::cout << "amount:" << this->_amount <<";";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<";";
	std::cout << "amount:" << this->_amount <<";";
	std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	if (deposit < 0)
		return ;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<";";
	std::cout << "p_amount:" << this->_amount <<";";
	std::cout << "deposit:" << deposit <<";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount <<";";
	this->_nbDeposits++;
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<";";
	std::cout << "p_amount:" << this->_amount <<";";
	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	this->_nbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	std::cout << "amount:" << this->_amount <<";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	return true;
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<";";
	std::cout << "amount:" << this->_amount <<";";
	std::cout << "deposits:" << this->_nbDeposits <<";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}


void	Account::_displayTimestamp( void )
{
	time_t time_now = time(NULL);
	struct tm *pLocal = localtime(&time_now);
	std::cout << '['
	<< pLocal->tm_year + 1900
	<< pLocal->tm_mon + 1
	<< pLocal-> tm_mday << "_"
	<< pLocal->tm_hour
	<< pLocal->tm_min
	<< pLocal->tm_sec
	<< "] ";
}
