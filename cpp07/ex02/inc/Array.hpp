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
		Array();
		Array( uint32_t n );

		// destructor
		~Array();

		// canonical form
		Array ( const Array& ref );
		Array &operator=( const Array& ref );

		// operator overload
		T& operator[]( uint32_t index );
		const T& operator[]( uint32_t index ) const;

		// public methods
		uint32_t size() const;

		// exceptions
		class Outbounds : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
};

#include "Array.tpp"