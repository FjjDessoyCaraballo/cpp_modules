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
			std::cerr << "Line " << line_count << std::endl; // for debugging
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
	return (matrix);
}

bool Database::parseDate(std::multimap<std::string, float> matrix)
{
    for (auto it = matrix.begin(); it != matrix.end(); ++it)
    {
        // check the first column for the dates
        const std::string& date = it->first;
        size_t first_hyphen = date.find('-');
        size_t second_hyphen = date.rfind('-');
        
        if (first_hyphen == std::string::npos || second_hyphen == std::string::npos || first_hyphen == second_hyphen)
            return (false);
            
        try {
            size_t year = std::stoi(date.substr(0, first_hyphen));
            size_t month = std::stoi(date.substr(first_hyphen + 1, second_hyphen - first_hyphen - 1));
            size_t day = std::stoi(date.substr(second_hyphen + 1));
            
            if (month < 1 || month > 12)
                return (false);
            if (day < 1 || day > 31)
                return (false);
            if (month == 2) {
                bool leap_year = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
                if (leap_year && day > 29)
                    return (false);
                if (!leap_year && day > 28)
                    return (false);
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11) {
                if (day > 30)
                    return (false);
            }
        }
        catch (const std::exception& e) {
            return (false); // Error in conversion
        }
    }
    return (true);
}

void	Database::applyExchangeRate()
{
	for (auto it = _injectionTable.begin(); it != _injectionTable.end(); ++it)
	{
		const std::string& injDate = it->first;
		const float injValue = it->second;
		bool match = false;

		for (auto db_it = _matrixDb.begin(); db_it != _matrixDb.end(); ++db_it)
		{
			const std::string& dbDate = db_it->first;
			const float dbValue = db_it->second;

			if (injDate == dbDate)
			{
				if (parseDate(injDate) == false)
				{
					std::cout << "Error: bad input => " << injDate << std::endl;
					break ;
				}
				else
				{
					std::cout << injDate << " => " << dbValue << " = " << (dbValue * injValue) << std::endl;
					match = true;
					break ;
				}
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
				std::cout << prevDate << " (" << injDate << ")" << " => " << prevValue << (prevValue * injValue) << std::endl;
			}
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
