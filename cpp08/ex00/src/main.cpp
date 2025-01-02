/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/easyfind.hpp"

int main(void)
{
	std::cout << " ### TEST ONE ### " << std::endl;
	{
		std::vector<int>vec = {1,2,3,8,5,6,7,9};
		::easyfind(vec, 8);
	}

	std::cout << std::endl;
	std::cout << " ### TEST TWO ### " << std::endl;

	{
		std::vector<int>vec = {0,0,0,0,0,0,0};
		easyfind(vec, 8);
	}
	std::cout << std::endl;

	std::cout << " ### TEST THREE ### " << std::endl;

	{
		std::vector<int>vec = {8,8,8,8,8,8,8,8,8};
		::easyfind(vec, 8);
	}

	std::cout << std::endl;
	std::cout << " ### TEST FOUR ### " << std::endl;

	{
		std::vector<int>vec = {1235, 56834564, 58, -12313, -8};
		::easyfind(vec, 8);
	}

	std::cout << std::endl;
	std::cout << " ### TEST FIVE ### " << std::endl;

	{
		std::vector<int>vec = {-8,-8,-8,-8,-8,-8,0,8};
		::easyfind(vec, 8);
	}
	
	return (0);
}