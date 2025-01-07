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
#include <fstream>
#include <stdexcept>

class Database
{
	private:
		std::fstream filedb;
		std::fstream subdb;
	public:
		// constructor
		Database( std::string newdb );

		// destructor
		~Database();
		
		// canonical form
		Database( const Database& ref );
		Database &operator=( const Database& ref );

		// public methods


		// exceptions
		class MissingDb : std::exception
		{
			public:
				const char* what() const noexcept override;
		};
		class MissingNewDb : std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};