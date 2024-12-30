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
	std::vector<int>vec = {1,2,3,4,5,6,7,9};
	int result = ::easyfind(vec, 8);

	if (result == -1)
		return (-1);
	
	return (0);
}