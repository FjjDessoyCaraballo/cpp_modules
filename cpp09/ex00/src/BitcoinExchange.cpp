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
#include <iostream>

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
	std::cout << "The problem is in the injections" << std::endl;
	this->_injectionTable = setMatrix(this->_inj, true);
	if (this->_fileDb.is_open())
	this->_fileDb.close();
	if (this->_inj.is_open())
	this->_inj.close();
	applyExchangeRate();
}

Database::~Database() {}

Database::Database( const Database& ref ) { static_cast<void>(ref); }

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
		size_t separator = 0;
		if (injection == false)
			separator = line.find(',');
		else
			separator = line.find(" | ");
		if (separator == std::string::npos)
		{
			std::cerr << "Line " << line_count << std::endl; // for debugging
			throw DbFormat();
		}
		std::string date = line.substr(0, separator);
		if (date.empty())
			throw DbFormat();
		std::string valueStr;
		if (!injection)
			valueStr = line.substr(separator + 1);
		else
			valueStr = line.substr(separator + 3);
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
	return (matrix);
}

bool Database::parseDate(std::string date)
{
    // Check for basic format YYYY-MM-DD
    size_t first_hiphen = date.find('-');
    size_t second_hiphen = date.rfind('-');
    
    if (first_hiphen == std::string::npos || second_hiphen == std::string::npos || first_hiphen == second_hiphen)
        return (false);
    
    try
	{
        size_t year = std::stoi(date.substr(0, first_hiphen));
        size_t month = std::stoi(date.substr(first_hiphen + 1, second_hiphen - first_hiphen - 1));
        size_t day = std::stoi(date.substr(second_hiphen + 1));
    
        if (month < 1 || month > 12)
            return (false);
            
        // Check valid day range based on month
        const size_t daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        size_t maxDays = daysInMonth[month];
        
        if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
            maxDays = 29;
            
        if (day < 1 || (day > maxDays))
            return (false);
        
		if (year < 2009)
			return (false);

		if (year == 2009 && month == 1 && day == 1)
			return (false);

        return (true);
    }
    catch (const std::exception& e) {
        return false;
	}
}

void	Database::applyExchangeRate()
{
	for (auto it = _injectionTable.begin(); it != _injectionTable.end(); ++it)
	{
		if (it->second > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		if (it->second < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (parseDate(it->first) == false)
		{
			std::cout << "Error: bad input => " << it->first << std::endl;
			continue ;
		}
		const std::string& injDate = it->first;
		const float injValue = it->second;
		bool match = false;

		for (auto db_it = _matrixDb.begin(); db_it != _matrixDb.end(); ++db_it)
		{
			const std::string& dbDate = db_it->first;
			const float dbValue = db_it->second;

			if (injDate == dbDate)
			{
				std::cout << injDate << " => " << dbValue << " = " << (dbValue * injValue) << std::endl;
				match = true;
				break ;
			}
		}
		if (match == false) // no exact match found
		{
			auto prev_it = _matrixDb.upper_bound(injDate);
			if (prev_it != _matrixDb.begin())
			{
				--prev_it; // Move iterator to the largest date less than injDate
				const std::string& prevDate = prev_it->first;
				const float prevValue = prev_it->second;
				std::cout << injDate << " (" << prevDate << ")" << " => " << prevValue << " = " << (prevValue * injValue) << std::endl;			}
			else
				std::cout << "No exact or earlier date found for " << injDate << "." << std::endl;
		}
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
