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

#include <vector>
#include <cstdint>
#include <iostream>

class PmergeMe {
	private:
		std::vector<std::pair<uint64_t, uint64_t>>	_pairs;
		uint64_t									_oddElement;
		bool										_hasOddElement;
		// need a second container after pairing;
	public:
		// constructor
		PmergeMe( int argc, char* array[] );
		
		//destructor
		~PmergeMe();
		
		// canonical form
		PmergeMe(const PmergeMe& ref);
		PmergeMe& operator=(const PmergeMe& ref);
		
		// public methods
		void	printPairs(void) const;

		// getters
		const std::vector<std::pair<uint64_t, uint64_t>>	&getPairs() const;

		// setters
		void	setPairs( int argc, char** array );

};