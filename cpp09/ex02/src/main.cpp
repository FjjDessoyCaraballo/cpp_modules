/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/PmergeMe.hpp"
#include <map>

/**
 * 1. Pair elements and compare within each pair
 * 2. Recursively sort the larger elements from each pair
 * 3. Insert the smaller elements using a specific sequence (Jacobsthal numbers)
 */

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		// setting a regular vector to output the input given before sorting
		std::vector<uint64_t> original;
		try {
			for (int i = 1; i < argc; i++)
			{
				long val = std::stol(argv[i]);
				original.push_back(val);
			}
		} catch (std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			return (EXIT_FAILURE);
		}
		std::cout << "before: ";
		for (auto it = original.begin(); it != original.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << "(argc: " << argc -1 << ")";
		std::cout << std::endl;

		// DEBUGGING AND SANITY TEST

		// std::cout << "[size] : " << original.size() << std::endl;
		// std::multiset<uint64_t> sort;
		// for (auto it = original.begin(); it != original.end(); it++)
		// {
		// 	sort.insert(*it);
		// }
		// std::cout << "multiset: ";
		// for (auto it = sort.begin(); it != sort.end(); it++)
		// {
		// 	std::cout << *it << " ";
		// }
		// std::cout << std::endl;
		// std::cout << "[size] : " << sort.size() << std::endl;

		// the algorithm is applied automatically with the contruction
		PmergeMe terribleAlgorithm;
		terribleAlgorithm.setPairs(argc, argv);
		terribleAlgorithm.printResult();
	}
	else
	{
		std::cerr << "Usage: ./PmergeMe integer1 integer2 [...]" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}