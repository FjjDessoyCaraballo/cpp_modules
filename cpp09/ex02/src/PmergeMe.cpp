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

PmergeMe::PmergeMe( char** array )
{

}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe& ref )
{
	operator=(ref);
}

PmergeMe	&PmergeMe::operator=( const PmergeMe& ref )
{
	if (this == &ref)
		return (*this);	
	this->_pairs = ref._pairs;
	return (*this);
}

const std::vector<std::pair<uint64_t, uint64_t>>	&PmergeMe::getPairs() const
{
	return (this->_pairs);
}

void	PmergeMe::setPairs( char** array )
{
	try {
		uint8_t i = 0;
		while (array[i])
		{
			if (array[i] && array[i + 1])
			{
				if (array[i + 1] > array[i])
					this->_pairs.push_back(std::make_pair(std::stol(array[i + 1]), std::stol(array[i])));
				else
					this->_pairs.push_back(std::make_pair(std::stol(array[i]), std::stol(array[i + 1])));
				i += 2;
			}
			else
				this->_pairs.push_back(std::make_pair(std::stol(array[i]), 0));
		}
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return ;
	}
}

void	PmergeMe::printPairs(void) const
{
	for (auto it = _pairs.begin(); it != _pairs.end(); ++it)
	{
		std::cout << "[" << 
	}
}