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
#include <deque>
#include <cstdint>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>

class PmergeMe {
	private:
		std::vector<std::pair<uint64_t, uint64_t>>			_pairsVector;
		std::deque<std::pair<uint64_t, uint64_t>>			_pairsDeque;
		std::vector<uint64_t>								_largeVecElem;
		std::deque<uint64_t>								_largeDeque;
		uint64_t											_oddElement;
		bool												_hasOddElement;
		uint64_t											_processingTime;
		uint64_t											_nbElements;

		// variables for calculating time
		std::chrono::high_resolution_clock::time_point		_start;
		std::chrono::high_resolution_clock::time_point		_end;
		std::chrono::duration<double, std::micro>			_durationVector;
		std::chrono::duration<double, std::micro>			_durationDeque;	

		// canonical form
		PmergeMe(const PmergeMe& ref);
		PmergeMe& operator=(const PmergeMe& ref);
		
		// methods for vector implementation
		void	sortLargeVector( int left, int right );
		void 	insertElementVector(std::vector<uint64_t>& sorted, uint64_t element);
		void 	JacobsthalVector();
		void	printLargerPairs();
		void	fJAVector();
		
		// methods for list implementation
		void	sortLargeDeque( int left, int right );
		void 	insertElementDeque(std::deque<uint64_t>& sorted, uint64_t element);
		void 	JacobsthalDeque();
		void 	fJADeque();
		
		// printer
		void	printPairs();
		
		// setters
		public:
		// constructor
		PmergeMe();
		
		//destructor
		~PmergeMe();
		
		// public methods
		void	setPairs( int argc, char** array );
		void	printResult();

};