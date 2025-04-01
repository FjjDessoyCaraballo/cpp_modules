# Ford-Johnson

This algorithm starts by grouping the sequence of numbers into pairs and with those pairs we separate any odd number that does not pair up.

During the pairing, we put the larger elements to the left and the smaller to the right. After pairing we sort recursively the larger elements.

Example sequence: [10, 5, 3, 7, 1, 44, 32, 97, 92, 56, 12, 19, 20]
What should look like sorted

### SORTING

Pair 0: (10, 5)  - larger element 10, smaller element 5
Pair 1: (7, 3)   - larger element 7, smaller element 3
Pair 2: (44, 1)  - larger element 44, smaller element 1
Pair 3: (97, 32) - larger element 97, smaller element 32
Pair 4: (92, 56) - larger element 92, smaller element 56
Pair 5: (19, 12) - larger element 19, smaller element 12

### AFTER SORTING

Pair 0: (10, 5)  - larger element 7, smaller element 5
Pair 1: (7, 3)   - larger element 10, smaller element 3
Pair 2: (44, 1)  - larger element 19, smaller element 1
Pair 3: (97, 32) - larger element 44, smaller element 32
Pair 4: (92, 56) - larger element 92, smaller element 56
Pair 5: (19, 12) - larger element 97, smaller element 12

SORTED LARGER SET
[7, 10, 19, 44, 92, 97]

smaller set to insert
[5, 3, 1, 32, 56, 12]

we take the first sub-sub-smaller element [10] with the sorted larger first index [7]
[7, 10]

smaller pairs
[5, 3]
[1, 32]
[56, 12]

### INSERTION

JACOBSTHAL NUMBERS
[ 0, 1, 1, 3, 5, 11, 21, 43, ...]

Jacobsthal first index is 1, so we pair the index 1 of our pairs:

#### First pair [7, 3]

Pair 1: [7, 3]   - larger element 7, smaller element 3
[*7*, 10, 19, 44, 92, 97]
We then insert [3] using binary search (std::lower_bound)
SORTED LARGER SET
[*3*, 7, 10, 19, 44, 92, 97]

#### Second pair [97, 32]

Pair 3: [97, 32]   - larger element 97, smaller element 32
[7, 10, 19, 44, 92, *97*]
We then insert [32] using binary search (std::lower_bound)
SORTED LARGER SET
[3, 7, 10, 19, *32*, 44, 92, 97]

#### Intermediate indices (e.g. pair 0)

For non-Jacobsthal indices we do it reversed
Pair 2: [10, 5]  - larger element 44, smaller element 1
We then insert [10] if it's not in the solution
if it is in the solution, we insert [5] using binary search (std::lower_bound)
[3, *5*, 7, 10, 19, 32, 44, 92, 97]

#### Intermediate indices (e.g. pair 2)

For non-Jacobsthal indices we do it reversed
Pair 2: (44, 1)  - larger element 44, smaller element 1
We then insert [44] if it's not in the solution
if it is in the solution, we insert [1] using binary search (std::lower_bound)
[*1*, 3, 5, 7, 10, 19, 32, 44, 92, 97]

#### Fifth pair [19, 12]

Pair 3: [19, 12]   - larger element 97, smaller element 32
[7, 10, *19*, 44, 92, 97]
We then insert [12] using binary search (std::lower_bound)
SORTED LARGER SET
[1, 3, 5, 7, 10, *12*, 19, 32, 44, 92, 97]

#### Intermediate indices (e.g. pair 4)

For non-Jacobsthal indices we do it reversed
Pair 2: [92, 56]  - larger element 44, smaller element 1
We then insert [92] if it's not in the solution
if it is in the solution, we insert [56] using binary search (std::lower_bound)
[1, 3, 5, 7, 10, 12, 19, 32, 44, *56*, 92, 97]

#### Insert odd element with binary to finish

Inserting [20] with `std::lower_bound()`
[1, 3, 5, 7, 10, 12, 19, *20*, 32, 44, 56, 92, 97]
