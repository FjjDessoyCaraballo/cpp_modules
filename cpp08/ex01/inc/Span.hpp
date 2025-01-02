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
#include <stdexcept>
#include <stdint.h>

class Span
{
	private:
		std::vector<int>	_container;
		uint32_t			_max;	
	public:
		// constructor
		Span( uint32_t limit );

		// destructor
		~Span();

		// canonical form
		Span( const Span& ref );
		Span 		&operator=( const Span& ref );

		// public methods
		void 		addNumber( uint32_t num );
		void		addRange( uint32_t range );
		uint32_t	shortestSpan();
		uint32_t	longestSpan();


		// exceptions
		class noSpan : std::exception
		{
			public:
				const char* what() const noexcept;
		};
};