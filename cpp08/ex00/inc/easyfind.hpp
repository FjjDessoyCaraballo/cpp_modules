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

template <typename T>
int easyfind(const T& container, int num) {
	int index = 0;
	for (auto iter = container.begin(); iter != container.end(); ++iter, ++index) {
		std::cout << *iter << "[" << index << "]" << std::endl;
		if (*iter == num) {
			std::cout << "Found element at index: " << index << std::endl;
			return (index);
		}
	}
	std::cerr << "Element not found" << std::endl;
	return (-1);
}
