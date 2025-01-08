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
	this->_inj.open(newdb, std::ios::in);
	if (!this->_inj.is_open()) {
		throw MissingNewDb();
	}
	this->_fileDb.open("./src/data.csv", std::ios::in);
	if (!this->_fileDb.is_open()) {
		throw MissingDb();
	}
	this->_matrixDb = setMatrix(this->_fileDb, false);
	this->_injectionTable = setMatrix(this->_inj, true);
	if (this->_fileDb.is_open())	
		this->_fileDb.close();
	if (this->_inj.is_open())
		this->_inj.close();
	// ### FOR DEBUGGING ###
	// for (auto it = _matrixDb.begin(); it != _matrixDb.end(); ++it)
	// {
	// 	std::cout << it->first << "," << it->second << std::endl;
	// }
	// for (auto it = _injectionTable.begin(); it != _injectionTable.end(); ++it)
	// {
	// 	std::cout << it->first << "," << it->second << std::endl;
	// }
	applyExchangeRate();
}

Database::~Database()
{
}

Database::Database( const Database& ref )
{
	static_cast<void>(ref);
}

Database &Database::operator=( const Database& ref )
{
	if (this == &ref)
		return (*this);
	static_cast<void>(ref);
	return (*this);
}

std::multimap<std::string, float> Database::setMatrix(std::fstream &file, bool injection)
{
	std::multimap<std::string, float> matrix;
	std::string line;
	size_t line_count = 0;
	
	if (injection == false && !std::getline(file, line))
		throw DbFormat();
    while (std::getline(file, line))
    {
		size_t comma_pos = line.find(',');
		if (comma_pos == std::string::npos)
		{
			std::cerr << "Line " << line_count << std::endl;
			throw DbFormat();
		}
		std::string date = line.substr(0, comma_pos);
		if (date.empty())
			throw DbFormat();
		std::string valueStr = line.substr(comma_pos + 1);
		if (valueStr.empty())
			throw DbFormat();		
		try 
		{
			float valueDb = std::stof(valueStr);
		    matrix.emplace(date, valueDb);
		} 
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Invalid argument: " << e.what() << " at line " << line_count << std::endl;
			throw DbFormat();
		} 
		catch (const std::out_of_range& e)
		{
			std::cerr << "Out of range: " << e.what() << " at line " << line_count << std::endl;
			throw DbFormat();
		}
		line_count++;
	}
	return matrix;
}

void	Database::applyExchangeRate()
{
	for (auto it = _injectionTable.begin(); it != _injectionTable.end(); ++it)
	{
		
	}
}

const char* Database::MissingDb::what() const noexcept
{
	return ("Missing data.csv file");
}

const char* Database::MissingNewDb::what() const noexcept
{
	return ("Missing secondary file");
}

const char* Database::DbFormat::what() const noexcept
{
	return ("Format of database is incorrect");
}
