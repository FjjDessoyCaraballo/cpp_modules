/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <limits.h>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
	public:
	// constructor
		
	// destructor

	// canonical form
		ScalarConverter( const ScalarConverter& ref );
		ScalarConverter& operator=( const ScalarConverter& ref );

	// public methods
		static void convert( std::string str );
};