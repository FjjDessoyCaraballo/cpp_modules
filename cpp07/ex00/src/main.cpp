/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/Template.hpp"
#include <iostream>

int main(void)
{
	int a = 2;
	int b = 69;

	std::cout << "Before the swap: " << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After the swap: " << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) " << ::min(a,b) << std::endl;
	std::cout << "max(a,b) " << ::max(a,b) << std::endl;

	std::string first = "chaine1";
	std::string second = "chaine2";

	::swap(first, second);
	std::cout << "first = " << first << ", second = " << second << std::endl;
	std::cout << "min(first, second) " << ::min(first,second) << std::endl;
	std::cout << "max(first, second) " << ::max(first,second) << std::endl;
	return (0);
}