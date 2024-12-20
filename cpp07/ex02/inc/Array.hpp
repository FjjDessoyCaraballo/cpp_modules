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

#include <iostream>
#include <stdexcept>
#include <cstdint>

template <typename T>
class Array
{
	private:
		T*			_array;
		uint32_t	_size;
	public:
		// constructors
		Array(): _array(nullptr), _size(0) {
			std::cout << "Array created without defined size" << std::endl;
		}
		Array( uint32_t n ): _array(new T[n]), _size(n) {
			std::cout << "Array created with size: " << n << std::endl;
		}

		// destructor
		~Array() {
			delete [] this->_array;
		}

		// canonical form
		Array ( const Array& ref ): _array(new T[ref._size]), _size(ref._size) {
			for (uint32_t i = 0; i < _size; i++) {
				this->_array[i] = ref._array[i];
			}
		}
		Array &operator=( const Array& ref ) {
			if (this == &ref)
				return (*this);
			delete [] this->_array;
			this->_array = new T[ref._size];
			this->_size = ref._size;
			for (uint32_t i = 0; i < this->_size; i++) {
				this->_array[i] = ref._array[i];
			}
			return (*this);
		}

		// operator overload
		T& operator[]( uint32_t index ) {
			if (index >= this->_size) {
				throw Outbounds();
			}
			return (this->_array[index]);
		}

		const T& operator[]( uint32_t index ) const {
			if (index >= this->_size) {
				throw Outbounds();
			}
			return (this->_array[index]);
		}

		// public methods
		uint32_t size() const {
			return (this->_size);
		}

		// exceptions
		class Outbounds : public std::exception
		{
			public:
				const char* what() const noexcept {
					return ("Out of bounds of the array");
				}
		};
};