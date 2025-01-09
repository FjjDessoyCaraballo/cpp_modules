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
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <limits>
#include <iomanip>

typedef enum type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE,
} 			type;

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
		static bool isDigit( int c );
		static bool isChar( std::string );
		static bool isInt( std::string );
		static bool isFloat( std::string );
		static bool isDouble( std::string );
		static void printChar( char c, bool print );
		static void printInt( long n, bool print );
		static void printFloat( float nf, std::string str, bool print );
		static void printDouble( double nd, std::string str, bool print );

};