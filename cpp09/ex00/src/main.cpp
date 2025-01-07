/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Error: could not open file. Usage: ./btc <db>" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string newfile(argv[1]);
	if (newfile.empty()) {
		std::cout << "Error: could not open file. Usage: ./btc <db>" << std::endl;
		return (EXIT_FAILURE);
	}
	try {
		Database db(newfile);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (0);
}