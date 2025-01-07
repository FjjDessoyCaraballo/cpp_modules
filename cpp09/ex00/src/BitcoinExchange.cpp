/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/BitcoinExchange.hpp"

Database::Database( std::string newdb )
{
	this->subdb.open(newdb, std::ios::in);
	if (!subdb.is_open()) {
		throw MissingNewDb();
	}
	this->filedb.open("./src/data.csv", std::ios::in);
	if (!this->filedb.is_open()) {
		throw MissingDb();
	}
}

Database::~Database()
{
	if (this->filedb.is_open())
		this->filedb.close();
	if (this->subdb.is_open())
		this->subdb.close();
}

Database::Database( const Database& ref )
{
	(void)ref;
}

Database &Database::operator=( const Database& ref )
{
	(void)ref;
	return (*this);
}

const char* Database::MissingDb::what() const noexcept
{
	return ("Missing data.csv file");
}

const char* Database::MissingNewDb::what() const noexcept
{
	return ("Missing secondary file");
}