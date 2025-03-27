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
#include <chrono>

PmergeMe::PmergeMe( int argc, char* array[] )
{
	_hasOddElement = false;

	_oddElement = 0;
	setPairs(argc, array);
	// printPairs(); // for debugging
	fordJohnsonAlgorithm();
	// printLargerPairs();
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe( const PmergeMe& ref ) { operator=(ref); }

PmergeMe	&PmergeMe::operator=( const PmergeMe& ref )
{
	if (this == &ref)
		return (*this);	
	this->_pairs = ref._pairs;
	return (*this);
}

const std::vector<std::pair<uint64_t, uint64_t>>	&PmergeMe::getPairs() const { return (this->_pairs); }

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
    // Check if there is something to sort
    if (_pairs.size() <= 1)
    {
        // For small cases, just sort directly
        for (const auto& pair : _pairs)
        {
            _largerElements.push_back(pair.first);
            _largerElements.push_back(pair.second);
        }

        if (_hasOddElement)
            _largerElements.push_back(_oddElement);
            
        // Sort the small array directly
        std::sort(_largerElements.begin(), _largerElements.end());
        return;
    }

    // Extract larger elements from each pair
    for (const auto& pair : _pairs)
        _largerElements.push_back(pair.first);

    // Recursively sort larger elements
    sortLargerElements(0, _largerElements.size() - 1);

    // Now use the Jacobsthal insertion method for smaller elements
    insertSmallerElementsWithJacobsthal();
}

void	PmergeMe::sortLargerElements( int left, int right )
{
	// check if there's something to
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
			// handle odd element
			hasUnpaired = true;
			unpaired = _largerElements[i];
		}
	}

	// Extract just the larger elements from the previous pairs
	std::vector<uint64_t> subLarger;
	for (const auto& pair: subPairs)
		subLarger.push_back(pair.first);

	// recursion to sort the larger elements
	for (size_t i = 0; i < subLarger.size(); i++)
		this->_largerElements[left + i] = subLarger[i];

	// use recursion to sort larger elements if there's more than one
	if (subLarger.size() > 1)
		sortLargerElements(left, left + subLarger.size() - 1);

	// temporary array to store the biggest elements in largerElements
	std::vector<uint64_t> sorted;
	for (uint64_t i = left; i < left + subLarger.size(); i++)
		sorted.push_back(_largerElements[i]);

	// binary insertion of the smaller elements of largerElements
	for (const auto& pair: subPairs)
		insertElement(sorted, pair.second);
	
	// binary insertion of the odd element
	if (hasUnpaired)
		insertElement(sorted, unpaired);

	// throw the sorted elements back into our vector
	for (size_t i = 0; i < sorted.size(); i++)
		_largerElements[left + i] = sorted[i];
}

// Binary insertion
void PmergeMe::insertElement(std::vector<uint64_t>& sorted, uint64_t element)
{
	auto it = std::lower_bound(sorted.begin(), sorted.end(), element);
	sorted.insert(it, element);
}

void PmergeMe::insertSmallerElementsWithJacobsthal()
{
    // Start with the first sorted larger element
    std::vector<uint64_t> result;
    if (!_largerElements.empty())
        result.push_back(_largerElements[0]);
    
    // Generate Jacobsthal numbers
    std::vector<int> jacobsthal(2, 0);
    jacobsthal[0] = 1;
    jacobsthal[1] = 3;
    while (jacobsthal.back() < static_cast<int>(_pairs.size()))
    {
        jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
    }
    
    // Insert in Jacobsthal order
    for (size_t j = 0; j < jacobsthal.size() && jacobsthal[j] < static_cast<int>(_pairs.size()); j++)
    {
        int index = jacobsthal[j];
        
        // Insert the element at this position
        if (index > 0 && index < static_cast<int>(_largerElements.size()))
        {
            // Add larger element if not already in result
            insertElement(result, _largerElements[index]);
            
            // Add corresponding smaller element
            insertElement(result, _pairs[index].second);
        }
        
        // Fill in elements between current and previous Jacobsthal numbers
        int prev = (j == 0) ? 0 : jacobsthal[j-1];
        for (int i = index - 1; i > prev; i--)
        {
            if (i > 0 && i < static_cast<int>(_largerElements.size()))
            {
                // Add larger element if not already in result
                insertElement(result, _largerElements[i]);
                
                // Add corresponding smaller element
                insertElement(result, _pairs[i].second);
            }
        }
    }
    
    // Insert any remaining elements that were not covered by Jacobsthal sequence
    for (size_t i = 1; i < _pairs.size(); i++)
    {
        // Check if this element has already been inserted
        if (std::find(result.begin(), result.end(), _largerElements[i]) == result.end())
        {
            insertElement(result, _largerElements[i]);
            insertElement(result, _pairs[i].second);
        }
    }
    
    // Insert odd element if present
    if (_hasOddElement)
        insertElement(result, _oddElement);
    
    // Update _largerElements with completely sorted array
    _largerElements = result;
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
		std::cout << "[" << elements << "] ";
	}
	std::cout << std::endl;
}

void PmergeMe::printResult()
{
	std::cout << "After: ";
	for (const auto& elements : _largerElements)
	{
		std::cout << elements << " ";
	}
	std::cout << std::endl;
}