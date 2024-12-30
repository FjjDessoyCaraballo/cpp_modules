/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
int easyfind(const T& container, int num) {
	try
	{
		for (size_t i = 0; i < container.size(); ++i)
		{
			if (container[i] == num)
			{
				std::cout << "Found the element in index: " << i << std::endl;
				return (i);
			}
		}
		throw std::runtime_error("element not found");
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return (-1);
	}
}