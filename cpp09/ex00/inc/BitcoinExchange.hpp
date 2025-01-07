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
		std::fstream				_filedb;
		std::fstream				_subdb;
		void						setMatrix( std::fstream &file );
		std::vector<std::string>	_dbDateColumn; // original db
		std::vector<int>			_dbValueColumn; // original db
		std::vector<std::string>	_injectDateColumn; // input
		std::vector<int>			_injectValueColumn; // input
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
		class DbFormat : std::exception
		{
			public:
				const char* what() const noexcept override;
		}
};