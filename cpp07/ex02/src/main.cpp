/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/Array.hpp"

int main() 
{
    Array<int> arr(5);
    for (uint32_t i = 0; i < arr.size(); i++) {
        arr[i] = i * 10;
    }
    for (uint32_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << std::endl;
    }

	/**
	 * one can instantiate the array without parameters, but if you try
	 * to access anything in the array, it will crash your program because
	 * it is empty (NULL).
	 * 
	 */

    return (0);
}
