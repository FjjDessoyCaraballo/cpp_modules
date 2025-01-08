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
#include <vector>

class Database
{
	private:
		std::fstream									_fileDb;
		std::fstream									_inj;
		std::vector<std::pair<std::string, float>>		_matrixDb; // db of two columns with only data
		std::vector<std::pair<std::string, float>>		_injectionTable; // exchange rate file
		std::vector<std::pair<std::string, float>>		setMatrix( std::fstream &file, bool print );
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
		class MissingDb : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
		class MissingNewDb : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
		class DbFormat : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
};