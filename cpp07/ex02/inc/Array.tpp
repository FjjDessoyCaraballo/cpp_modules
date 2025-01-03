/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "Array.hpp"

// Array.tpp

// Constructor definitions
template <typename T>
Array<T>::Array(): _array(new T[1]), _size(1) {
    std::cout << "Array created without defined size" << std::endl;
}

template <typename T>
Array<T>::Array( uint32_t n ): _array(new T[n]), _size(n) {
    std::cout << "Array created with size: " << n << std::endl;
}

// Destructor
template <typename T>
Array<T>::~Array() {
    delete[] this->_array;
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array& ref): _array(new T[ref._size]), _size(ref._size) {
    for (uint32_t i = 0; i < this->_size; i++) {
        this->_array[i] = ref._array[i];
    }
}

// Assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& ref) {
    if (this == &ref)
        return (*this);
    delete [] this->_array;
    this->_array = new T[ref._size];
    this->_size = ref._size;
    for (uint32_t i = 0; i < this->_size; i++)
        this->_array[i] = ref._array[i];
    return (*this);
}

// Operator overloads
template <typename T>
T& Array<T>::operator[](uint32_t index) {
    if (index >= this->_size) {
        throw Outbounds();
    }
    return this->_array[index];
}

template <typename T>
const T& Array<T>::operator[](uint32_t index) const {
    if (index >= this->_size) {
        throw Outbounds();
    }
    return this->_array[index];
}

// Public methods
template <typename T>
uint32_t Array<T>::size() const {
    return this->_size;
}

// Exception method
template <typename T>
const char* Array<T>::Outbounds::what() const noexcept {
    return "Out of bounds of the array";
}
