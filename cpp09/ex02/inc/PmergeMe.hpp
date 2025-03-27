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
#include <set>
#include <cstdint>
#include <iostream>
#include <algorithm>

class PmergeMe {
	private:
		std::vector<std::pair<uint64_t, uint64_t>>	_pairs;
		std::vector<uint64_t>						_largerElements;
		uint64_t									_oddElement;
		bool										_hasOddElement;
		uint64_t									_processingTime;
		
		// canonical form
		PmergeMe(const PmergeMe& ref);
		PmergeMe& operator=(const PmergeMe& ref);
		
		void	printPairs();
		void	sortLargerElements( int left, int right );
		void 	insertElement(std::vector<uint64_t>& sorted, uint64_t element);
		void 	insertSmallerElementsWithJacobsthal();
		void	printLargerPairs();
		
		// setters
		void	setPairs( int argc, char** array );
		public:
		// constructor
		PmergeMe();
		
		//destructor
		~PmergeMe();
		
		// public methods
		void	fordJohnsonAlgorithm(int argc, char* array[], int vec_or_list);
		void	printResult();

};