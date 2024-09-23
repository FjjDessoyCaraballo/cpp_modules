/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit): _amount(initial_deposit), _nbDeposits(0)
{
	_displayTimestamp();
	static int acc_index;
	_accountIndex = acc_index;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	acc_index++;
	_nbAccounts++;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	// can't make withdrawal if there is not enough money
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (0);
	}
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (1);
}

void Account::_displayTimestamp()
{
	time_t 	stamp;
	tm	*time_format;

	// std::cout << "[19920104_091532] "; // for running diffs

	stamp = time(NULL);
	time_format = std::localtime(&stamp);
	std::cout << "[" << time_format->tm_year + 1900;
	if (time_format->tm_mon < 10)
		std::cout << '0';
	std::cout << time_format->tm_mon;
	if (time_format->tm_mday < 10)
		std::cout << '0';
	std::cout << time_format->tm_mday;
	std::cout << "_";
	if (time_format->tm_hour < 10)
		std::cout << '0';
	std::cout << time_format->tm_hour;
	if (time_format->tm_min < 10)
		std::cout << '0';
	std::cout << time_format->tm_min;
	if (time_format->tm_sec)
		std::cout << '0';
	std::cout << time_format->tm_sec;
	std::cout << "] ";
}

int Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

int Account::checkAmount() const
{
	return (Account::_amount);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
	<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:"\
	<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}