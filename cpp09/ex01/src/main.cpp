/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/rpn.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string equation = argv[1];
	if (equation.empty())
		return (EXIT_FAILURE);
	try {
		std::cout << Rpn::outputResult(equation) << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Your pole has not been reversed!" << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}