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

PmergeMe::PmergeMe( int argc, char* array[] )
{
	_hasOddElement = false;
	_oddElement = 0;
	this->setPairs(argc, array);
	this->printPairs();
	this->fordJohnsonAlgorithm();
	this->printLargerPairs();
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

void	PmergeMe::setPairs( int argc, char** array )
{
	try {
		for (int i = 1; i < argc; i += 2) {
			if (i + 1 < argc) {
				long val1 = std::stol(array[i]);
				long val2 = std::stol(array[i + 1]);
			
			if (val2 > val1)
				_pairs.push_back(std::make_pair(val2, val1));
			else
				_pairs.push_back(std::make_pair(val1, val2));
			}
			else {
				_hasOddElement = true;
				_oddElement = std::stol(array[i]);
			}
		}
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return ;
	}
}

void PmergeMe::fordJohnsonAlgorithm()
{
	// check if there is something to sort
	if (_pairs.size() <= 1)
		return ;
	
	// solely large elements
	for (const auto& pair : _pairs)
		_largerElements.push_back(pair.first);
	
	// sort large elements
	sortLargerElements(0, _largerElements.size() - 1);

}

void	PmergeMe::sortLargerElements( int left, int right )
{
	// 0 or 1 element
	if (left >= right)
		return ;

	// helper variables
	std::vector<std::pair<uint64_t, uint64_t>> subPairs;
	bool hasUnpaired = false;
	uint64_t unpaired = 0;
	

	for (int i = left; i < right; i += 2)
	{
		if (i + 1 <= right)
		{
			if (_largerElements[i] > _largerElements[i + 1])
				subPairs.push_back(std::make_pair(_largerElements[i], _largerElements[i + 1]));
			else
				subPairs.push_back(std::make_pair(_largerElements[i + 1], _largerElements[i]));
		}
		else
		{
			// handle off element
			hasUnpaired = true;
			unpaired = _largerElements[i];
		}
	}

	// Extract just the larger elements from the previous pairs
	std::vector<uint64_t> subLarger;
	for (const auto& pair: subPairs)
		subLarger.push_back(pair.first);

	// recursion to sort the larger elements
	if (subLarger.size() > 1)
	{
		for (size_t i = 0; i < subLarger.size(); i++)
			this->_largerElements[left + i] = subLarger[i];
		sortLargerElements(left, left + subLarger.size() - 1);
	}

	std::vector<uint64_t> sorted;
	for (uint64_t i = left; i < left + subLarger.size(); i++)
		sorted.push_back(_largerElements[i]);
	
	// Insert smaller elements from the larger collection
	for (const auto& pair: subPairs)
		insertElement(sorted, pair.second);
	
	// insert unpaired large element if there is one
	if (hasUnpaired)
		insertElement(sorted, unpaired);

	// Copy sorted result back to _largerElements
	for (size_t i = 0; i < sorted.size(); i++)
		_largerElements[left + i] = sorted[i];

	// Now we should have the larger elements sorted
}

// Binary insertion
void PmergeMe::insertElement(std::vector<uint64_t>& sorted, uint64_t element)
{
	auto it = std::lower_bound(sorted.begin(), sorted.end(), element);
	sorted.insert(it, element);
}

void	PmergeMe::printPairs()
{
	for (auto it = _pairs.begin(); it != _pairs.end(); ++it)
	{
		std::cout << "[" << it->first << ", " << it->second << "]" << std::endl;
	}
	if (_hasOddElement == true)
	{
		std::cout << "[" << _oddElement << "]" << std::endl;
	}
	std::cout << "Size of vector: " << _pairs.size() << std::endl;
	std::cout << "size of larger elements vector: " << _largerElements.size() << std::endl;
}

void	PmergeMe::printLargerPairs()
{
	for (const auto& elements : _largerElements)
	{
		std::cout << "[" << elements << "]" << std::endl;
	}
}
