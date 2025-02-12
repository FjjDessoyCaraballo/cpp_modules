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
#include <stdexcept>

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cerr << "Usage: <integer 1> <integer 2>" << std::endl;
		return (1);
	}
	try {
		int a = std::stoi(argv[1]);
		int b = std::stoi(argv[2]);
		std::cout << "Before the swap: " << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "After the swap: " << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) " << ::min(a,b) << std::endl;
		std::cout << "max(a,b) " << ::max(a,b) << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	{
		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) " << ::max(c, d) << std::endl;
	}
	return (0);
}