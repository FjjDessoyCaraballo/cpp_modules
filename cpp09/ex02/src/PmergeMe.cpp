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

PmergeMe::PmergeMe()
{
	_hasOddElement = false;
	_oddElement = 0;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe( const PmergeMe& ref ) { operator=(ref); }

PmergeMe	&PmergeMe::operator=( const PmergeMe& ref )
{
	if (this == &ref)
		return (*this);	
	this->_pairsVector = ref._pairsVector;
	return (*this);
}

void	PmergeMe::setPairs( int argc, char** array )
{
	_nbElements = argc - 1;
	_start = std::chrono::high_resolution_clock::now();
	try {
		for (int i = 1; i < argc; i += 2)
		{
			if (i + 1 < argc) 
			{
				long val1 = std::stol(array[i]);
				long val2 = std::stol(array[i + 1]);
				
				if (val2 > val1)
				_pairsVector.push_back(std::make_pair(val2, val1));
				else
				_pairsVector.push_back(std::make_pair(val1, val2));
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
	fJAVector();
	_end = std::chrono::high_resolution_clock::now();
	_durationVector = std::chrono::duration<double, std::micro>(_end - _start);

	_start = std::chrono::high_resolution_clock::now();
	try {
		for (int i = 1; i < argc; i += 2)
		{
			if (i + 1 < argc) 
			{
				long val1 = std::stol(array[i]);
				long val2 = std::stol(array[i + 1]);
				
				if (val2 > val1)
				_pairsDeque.push_back(std::make_pair(val2, val1));
				
				else
				_pairsDeque.push_back(std::make_pair(val2, val1));	
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
	fJADeque();
	_end = std::chrono::high_resolution_clock::now();
	_durationDeque = std::chrono::duration<double, std::micro>(_end - _start);

}

void PmergeMe::fJAVector()
{
	// printPairs(); // for debugging
	// printLargerPairs(); // for debugging
	
	// Check if there is something to sort
	if (_pairsVector.size() <= 1)
	{
		// For small cases, just sort directly
		for (const auto& pair : _pairsVector)
		{
			_largeVecElem.push_back(pair.first);
			_largeVecElem.push_back(pair.second);
		}
	
		if (_hasOddElement)
			_largeVecElem.push_back(_oddElement);
			
		// Sort the small array directly
		std::sort(_largeVecElem.begin(), _largeVecElem.end());
		return;
	}
	
	// Extract larger elements from each pair
	for (const auto& pair : _pairsVector)
		_largeVecElem.push_back(pair.first);

	// Recursively sort larger elements
	sortLargeVector(0, _largeVecElem.size() - 1);

	// Now use the Jacobsthal insertion method for smaller elements
	JacobsthalVector();
}

void PmergeMe::fJADeque()
{
	// printPairs(); // for debugging
	// printLargerPairs(); // for debugging
	
	// Check if there is something to sort
	if (_pairsDeque.size() <= 1)
	{
		// For small cases, just sort directly
		for (const auto& pair : _pairsDeque)
		{
			_largeDeque.push_back(pair.first);
			_largeDeque.push_back(pair.second);
		}
	
		if (_hasOddElement)
			_largeDeque.push_back(_oddElement);
			
		// Sort the small array directly
		std::sort(_largeDeque.begin(), _largeDeque.end());
		return;
	}
	
	// Extract larger elements from each pair
	for (const auto& pair : _pairsDeque)
		_largeDeque.push_back(pair.first);

	// Recursively sort larger elements
	sortLargeDeque(0, _largeDeque.size() - 1);

	// Now use the Jacobsthal insertion method for smaller elements
	JacobsthalDeque();
}

void	PmergeMe::sortLargeDeque( int left, int right )
{
	// check if there's something to
	if (left >= right)
		return ;

	// helper variables
	std::deque<std::pair<uint64_t, uint64_t>> subPairs;
	bool hasUnpaired = false;
	uint64_t unpaired = 0;
	
	for (int i = left; i < right; i += 2)
	{
		if (i + 1 <= right)
		{
			if (_largeDeque[i] > _largeDeque[i + 1])
				subPairs.push_back(std::make_pair(_largeDeque[i], _largeDeque[i + 1]));
			else
				subPairs.push_back(std::make_pair(_largeDeque[i + 1], _largeDeque[i]));
		}
		else
		{
			// handle odd element
			hasUnpaired = true;
			unpaired = _largeDeque[i];
		}
	}

	// Extract just the larger elements from the previous pairs
	std::deque<uint64_t> subLarger;
	for (const auto& pair: subPairs)
		subLarger.push_back(pair.first);

	// recursion to sort the larger elements
	for (size_t i = 0; i < subLarger.size(); i++)
		this->_largeDeque[left + i] = subLarger[i];

	// use recursion to sort larger elements if there's more than one
	if (subLarger.size() > 1)
		sortLargeVector(left, left + subLarger.size() - 1);

	// temporary array to store the biggest elements in largerElements
	std::deque<uint64_t> sorted;
	for (uint64_t i = left; i < left + subLarger.size(); i++)
		sorted.push_back(_largeDeque[i]);

	// binary insertion of the smaller elements of largerElements
	for (const auto& pair: subPairs)
		insertElementDeque(sorted, pair.second);
	
	// binary insertion of the odd element
	if (hasUnpaired)
		insertElementDeque(sorted, unpaired);

	// throw the sorted elements back into our vector
	for (size_t i = 0; i < sorted.size(); i++)
		_largeDeque[left + i] = sorted[i];
}

void	PmergeMe::sortLargeVector( int left, int right )
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
			if (_largeVecElem[i] > _largeVecElem[i + 1])
				subPairs.push_back(std::make_pair(_largeVecElem[i], _largeVecElem[i + 1]));
			else
				subPairs.push_back(std::make_pair(_largeVecElem[i + 1], _largeVecElem[i]));
		}
		else
		{
			// handle odd element
			hasUnpaired = true;
			unpaired = _largeVecElem[i];
		}
	}

	// Extract just the larger elements from the previous pairs
	std::vector<uint64_t> subLarger;
	for (const auto& pair: subPairs)
		subLarger.push_back(pair.first);

	// recursion to sort the larger elements
	for (size_t i = 0; i < subLarger.size(); i++)
		this->_largeVecElem[left + i] = subLarger[i];

	// use recursion to sort larger elements if there's more than one
	if (subLarger.size() > 1)
		sortLargeVector(left, left + subLarger.size() - 1);

	// temporary array to store the biggest elements in largerElements
	std::vector<uint64_t> sorted;
	for (uint64_t i = left; i < left + subLarger.size(); i++)
		sorted.push_back(_largeVecElem[i]);

	// binary insertion of the smaller elements of largerElements
	for (const auto& pair: subPairs)
		insertElementVector(sorted, pair.second);
	
	// binary insertion of the odd element
	if (hasUnpaired)
		insertElementVector(sorted, unpaired);

	// throw the sorted elements back into our vector
	for (size_t i = 0; i < sorted.size(); i++)
		_largeVecElem[left + i] = sorted[i];
}

// Binary insertion for vector
void PmergeMe::insertElementVector(std::vector<uint64_t>& sorted, uint64_t element)
{
	auto it = std::lower_bound(sorted.begin(), sorted.end(), element);
	sorted.insert(it, element);
}

// Binary insertion for dequqe
void PmergeMe::insertElementDeque(std::deque<uint64_t>& sorted, uint64_t element)
{
	auto it = std::lower_bound(sorted.begin(), sorted.end(), element);
	sorted.insert(it, element);
}

void PmergeMe::JacobsthalVector()
{
    // Start with the first sorted larger element
    std::vector<uint64_t> result;
    if (!_largeVecElem.empty())
        result.push_back(_largeVecElem[0]);
    
    // Add the second element's smaller part immediately (optimization)
    if (_pairsVector.size() > 0)
        insertElementVector(result, _pairsVector[0].second);
    
    // Generate Jacobsthal numbers
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(1); // Start with 1 (we've already handled index 0)
    jacobsthal.push_back(3);
    
    while (jacobsthal.back() < _pairsVector.size())
    {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    
    // Keep track of which indices we've processed
    std::vector<bool> processed(_pairsVector.size(), false);
    processed[0] = true; // Mark first element as processed
    
    // Process elements according to Jacobsthal sequence
    for (size_t j = 0; j < jacobsthal.size(); j++)
    {
        size_t curr = jacobsthal[j];
        if (curr < _pairsVector.size())
        {
            // Insert the larger element if not already in result
            if (std::find(result.begin(), result.end(), _largeVecElem[curr]) == result.end())
                insertElementVector(result, _largeVecElem[curr]);
            
            // Insert the smaller element
            insertElementVector(result, _pairsVector[curr].second);
            processed[curr] = true;
        }
        
        // Process intermediate elements in reverse order (important for efficiency)
        size_t prev = (j == 0) ? 0 : jacobsthal[j-1];
        for (size_t i = curr - 1; i > prev; i--)
        {
            if (i < _pairsVector.size() && !processed[i])
            {
                // Insert the larger element if not already in result
                if (std::find(result.begin(), result.end(), _largeVecElem[i]) == result.end())
                    insertElementVector(result, _largeVecElem[i]);
                
                // Insert the smaller element
                insertElementVector(result, _pairsVector[i].second);
                processed[i] = true;
            }
        }
    }
    
    // Process any remaining elements
    for (size_t i = 1; i < _pairsVector.size(); i++)
    {
        if (!processed[i])
        {
            // Insert larger element if not already in result
            if (std::find(result.begin(), result.end(), _largeVecElem[i]) == result.end())
                insertElementVector(result, _largeVecElem[i]);
            
            // Insert smaller element
            insertElementVector(result, _pairsVector[i].second);
        }
    }
    
    // Insert odd element if present
    if (_hasOddElement)
        insertElementVector(result, _oddElement);
    
    // Update _largeVecElem with the fully sorted result
    _largeVecElem = result;
}

void PmergeMe::JacobsthalDeque()
{
    // Start with the first sorted larger element
    std::deque<uint64_t> result;
    if (!_largeDeque.empty())
        result.push_back(_largeDeque[0]);
    
    // Add the second element's smaller part immediately (optimization)
    if (_pairsDeque.size() > 0)
        insertElementDeque(result, _pairsDeque[0].second);
    
    // Generate Jacobsthal numbers
    std::deque<size_t> jacobsthal;
    jacobsthal.push_back(1); // Start with 1 (we've already handled index 0)
    jacobsthal.push_back(3);
    
    while (jacobsthal.back() < _pairsVector.size())
    {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    
    // Keep track of which indices we've processed
    std::deque<bool> processed(_pairsDeque.size(), false);
    processed[0] = true; // Mark first element as processed
    
    // Process elements according to Jacobsthal sequence
    for (size_t j = 0; j < jacobsthal.size(); j++)
    {
        size_t curr = jacobsthal[j];
        if (curr < _pairsVector.size())
        {
            // Insert the larger element if not already in result
            if (std::find(result.begin(), result.end(), _largeDeque[curr]) == result.end())
                insertElementDeque(result, _largeDeque[curr]);
            
            // Insert the smaller element
            insertElementDeque(result, _pairsDeque[curr].second);
            processed[curr] = true;
        }
        
        // Process intermediate elements in reverse order (important for efficiency)
        size_t prev = (j == 0) ? 0 : jacobsthal[j-1];
        for (size_t i = curr - 1; i > prev; i--)
        {
            if (i < _pairsDeque.size() && !processed[i])
            {
                // Insert the larger element if not already in result
                if (std::find(result.begin(), result.end(), _largeDeque[i]) == result.end())
                    insertElementDeque(result, _largeDeque[i]);
                
                // Insert the smaller element
                insertElementDeque(result, _pairsDeque[i].second);
                processed[i] = true;
            }
        }
    }
    
    // Process any remaining elements
    for (size_t i = 1; i < _pairsDeque.size(); i++)
    {
        if (!processed[i])
        {
            // Insert larger element if not already in result
            if (std::find(result.begin(), result.end(), _largeDeque[i]) == result.end())
                insertElementDeque(result, _largeDeque[i]);
            
            // Insert smaller element
            insertElementDeque(result, _pairsDeque[i].second);
        }
    }
    
    // Insert odd element if present
    if (_hasOddElement)
        insertElementDeque(result, _oddElement);
    
    // Update _largeVecElem with the fully sorted result
    _largeDeque = result;
}

void	PmergeMe::printPairs()
{
	for (auto it = _pairsVector.begin(); it != _pairsVector.end(); ++it)
	{
		std::cout << "[" << it->first << ", " << it->second << "]" << std::endl;
	}
	if (_hasOddElement == true)
	{
		std::cout << "[" << _oddElement << "]" << std::endl;
	}
	std::cout << "Size of vector: " << _pairsVector.size() << std::endl;
	std::cout << "size of larger elements vector: " << _largeVecElem.size() << std::endl;

	for (auto it = _pairsDeque.begin(); it != _pairsDeque.end(); ++it)
	{
		std::cout << "[" << it->first << ", " << it->second << "]" << std::endl;
	}
	if (_hasOddElement == true)
	{
		std::cout << "[" << _oddElement << "]" << std::endl;
	}
	std::cout << "Size of deque: " << _pairsDeque.size() << std::endl;
	std::cout << "size of larger elements deque: " << _largeDeque.size() << std::endl;

}

void	PmergeMe::printLargerPairs()
{
	for (const auto& elements : _largeVecElem)
	{
		std::cout << "[" << elements << "] ";
	}
	std::cout << std::endl;

	for (const auto& elements : _largeDeque)
	{
		std::cout << "[" << elements << "] ";
	}
	std::cout << std::endl;
}

void PmergeMe::printResult()
{
	std::cout << "after (vector): ";
	for (auto it = _largeVecElem.begin(); it != _largeVecElem.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	// std::cout << "[size] : " << _largeVecElem.size() << std::endl; // debugging

	std::cout << "after (deque): ";
	for (auto it = _largeDeque.begin(); it != _largeDeque.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	// std::cout << "[size] : " << _largeDeque.size() << std::endl; // debugging

	std::cout << "Time to process a range of " << _nbElements << " elements with std::vector : " << std::fixed << std::setprecision(5) << _durationVector.count() << " us" << std::endl;
	std::cout << "Time to process a range of " << _nbElements << " elements with std::deque : " << std::fixed << std::setprecision(5) << _durationDeque.count() << " us" << std::endl;
}