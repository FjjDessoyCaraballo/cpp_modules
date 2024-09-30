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

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		Harl harl;
		harl.complain("debug");
		harl.complain("info");
		harl.complain("warning");
		harl.complain("error");
	}
	else
	{
		std::cout << "Harl is disappointed in you" << std::endl;
	}
	return (0);
}
