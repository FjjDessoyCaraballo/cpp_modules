/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/iter.hpp"
#include <iostream>

void increment(int &i)
{
	i += 1;
}

int main(void)
{
	int numbers[] = {1,2,3,4,5};
	uint32_t len = sizeof(numbers) / sizeof(numbers[0]);

	for (uint32_t i = 0; i < len; i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	::iter(numbers, len, increment);

	for (uint32_t i = 0; i < len; i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	return (0);
}