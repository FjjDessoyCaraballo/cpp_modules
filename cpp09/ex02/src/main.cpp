/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include <iostream>
#include "../inc/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		PmergeMe terribleAlgorithm(argv);
	}
	else
	{
		std::cerr << "Usage: ./PmergeMe integer1 integer2 [...]" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}