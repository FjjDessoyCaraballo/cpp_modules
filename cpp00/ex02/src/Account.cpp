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
	std::cout << "index:" << acc_index++ << ";amount:" << _amount << ";created" << std::endl;
	acc_index++;
	_nbAccounts++;
}

Account::~Account(void)
{

}