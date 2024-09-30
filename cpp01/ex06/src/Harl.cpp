/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::complain( std::string level )
{
	typedef void (Harl::*btc)();
	int i = 0;
	btc arr[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string lvls[4] = { "debug", "info", "warning", "error" };

	while (i < 4)
	{
		if (level.compare(lvls[i]) == 0)
			break;
		i++;
	}
	if (i == 4)
		return ;
	(this->*arr[i])();
	return ;
}

void	Harl::debug( void )
{
	std::cout << "------------- LEVEL 1 DEBUG -------------------" << std::endl;
	std::cout << "Have you ever thought that birds could be real?" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << std::endl;
}
void	Harl::info( void )
{
	std::cout << "------------- LEVEL 2 INFO --------------------" << std::endl;
	std::cout << "Like, I swear to God, they are out there flying." << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << std::endl;
}
void	Harl::warning( void )
{
	std::cout << "------------- LEVEL 3 WARNING -----------------" << std::endl;
	std::cout << "NO! NOT EVERYTHING IS A CONSPIRACY, LINDA!" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	Harl::error ( void )
{
	std::cout << "------------- LEVEL 4 ERROR -------------------" << std::endl;
	std::cout << "I simply cannot believe that I married you." << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << std::endl;
}
