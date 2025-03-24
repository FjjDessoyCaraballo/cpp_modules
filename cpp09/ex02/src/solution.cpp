void PmergeMe::fordJohnsonAlgorithm(void) {
    // Base case: if 0 or 1 pair, nothing to sort
    if (_pairs.size() <= 1) {
        return;
    }
    

	
    
    // Sort larger elements using recursive merge-insertion sort
    sortLargerElements(0, _largerElements.size() - 1);
    
    // Update the pairs with sorted larger elements
    for (size_t i = 0; i < _pairs.size(); i++) {
        _pairs[i].first = _largerElements[i];
    }
    
    // Now insert the smaller elements using Jacobsthal sequence
    insertSmallerElements();
    
    // Finally, insert the odd element if it exists
    if (_hasOddElement) {
        insertOddElement();
    }
}

// Helper method to recursively sort larger elements
void PmergeMe::sortLargerElements(int left, int right) {
    // Base case: subarray has 0 or 1 element
    if (left >= right) {
        return;
    }
    
    // Create new subproblems by pairing elements
    std::vector<std::pair<uint64_t, uint64_t>> subPairs;
    bool hasUnpaired = false;
    uint64_t unpaired = 0;
    
    // Pair elements in the current range
    for (int i = left; i < right; i += 2) {
        if (i + 1 <= right) {
            // Pair up and ensure larger element is first
            if (_largerElements[i] > _largerElements[i+1]) {
                subPairs.push_back(std::make_pair(_largerElements[i], _largerElements[i+1]));
            } else {
                subPairs.push_back(std::make_pair(_largerElements[i+1], _largerElements[i]));
            }
        } else {
            // Handle odd element in this subrange
            hasUnpaired = true;
            unpaired = _largerElements[i];
        }
    }
    
    // Extract just the larger elements from these pairs
    std::vector<uint64_t> subLarger;
    for (const auto& pair : subPairs) {
        subLarger.push_back(pair.first);
    }
    
    // Recursively sort the larger elements
    if (subLarger.size() > 1) {
        // Create a temporary subrange
        for (size_t i = 0; i < subLarger.size(); i++) {
            _largerElements[left + i] = subLarger[i];
        }
        sortLargerElements(left, left + subLarger.size() - 1);
    }
    
    // Merge results back to original array
    std::vector<uint64_t> sorted;
    // First add the recursively sorted larger elements
    for (int i = left; i < left + subLarger.size(); i++) {
        sorted.push_back(_largerElements[i]);
    }
    
    // Insert smaller elements from each pair using binary insertion
    for (const auto& pair : subPairs) {
        insertElement(sorted, pair.second);
    }
    
    // Insert unpaired element if it exists
    if (hasUnpaired) {
        insertElement(sorted, unpaired);
    }
    
    // Copy sorted result back to _largerElements
    for (size_t i = 0; i < sorted.size(); i++) {
        _largerElements[left + i] = sorted[i];
    }
}

// Helper function for binary insertion
void PmergeMe::insertElement(std::vector<uint64_t>& sorted, uint64_t element) {
    auto it = std::lower_bound(sorted.begin(), sorted.end(), element);
    sorted.insert(it, element);
}

// Insert smaller elements from pairs according to Jacobsthal sequence
void PmergeMe::insertSmallerElements() {
    std::vector<uint64_t> result;
    
    // Add first element as base case
    if (!_largerElements.empty()) {
        result.push_back(_largerElements[0]);
    }
    
    // Generate Jacobsthal numbers to determine insertion order
    std::vector<int> jacobsthalIndices = generateJacobsthalIndices(_pairs.size());
    
    // Insert according to Jacobsthal sequence
    for (int index : jacobsthalIndices) {
        if (index < static_cast<int>(_pairs.size())) {
            // Add larger element if not already in result
            if (result.empty() || result.back() != _largerElements[index]) {
                insertElement(result, _largerElements[index]);
            }
            
            // Insert smaller element using binary search
            insertElement(result, _pairs[index].second);
        }
    }
    
    // Update _largerElements with the fully sorted result
    _largerElements = result;
}

// Generate Jacobsthal indices for insertion sequence
std::vector<int> PmergeMe::generateJacobsthalIndices(size_t n) {
    std::vector<int> indices;
    
    // Add index 0 as base case
    indices.push_back(0);
    
    // Calculate Jacobsthal numbers
    std::vector<int> jacobsthal = {0, 1};
    while (jacobsthal.back() < static_cast<int>(n)) {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    
    // Generate indices based on Jacobsthal differences
    for (size_t i = 2; i < jacobsthal.size(); i++) {
        for (int j = jacobsthal[i] - 1; j > jacobsthal[i-1] - 1; j--) {
            if (j < static_cast<int>(n) && j > 0) {
                indices.push_back(j);
            }
        }
    }
    
    // Add remaining indices in order
    for (size_t i = 1; i < n; i++) {
        if (std::find(indices.begin(), indices.end(), i) == indices.end()) {
            indices.push_back(i);
        }
    }
    
    return indices;
}

// Insert the odd element into the sorted array
void PmergeMe::insertOddElement() {
    if (_hasOddElement) {
        insertElement(_largerElements, _oddElement);
    }
}