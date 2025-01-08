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

// TO DO:
/**
 * 1. find a way to parse out the input document in a scalable way;
 * 2. find out what can be acceptable input;
 * 3. make the exchange operations.
 * 
 * Matrix with the .csv file is done. All we need to do is match with input
 */

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
}

Database::~Database()
{
	if (this->_fileDb.is_open())
		this->_fileDb.close();
	if (this->_inj.is_open())
		this->_inj.close();
}

Database::Database( const Database& ref )
{
	static_cast<void>(ref);
}

Database &Database::operator=( const Database& ref )
{
	static_cast<void>(ref);
	return (*this);
}


std::vector<std::pair<std::string, float>>	Database::setMatrix( std::fstream &file, bool print )
{
	std::vector<std::string>	file_parse;
	std::vector<std::string>	dbDateColumn;
	std::vector<float>			dbValueColumn;
	std::string 				line;
	size_t 						line_count = 0; // for throwing informative exceptions

	if (!std::getline(file,line)) // for skipping the header row
		throw DbFormat();
	while (std::getline(file, line))
	{
		file_parse.push_back(line); // at this point we have the whole file in a container
		size_t comma_pos = line.find(',');
		if (comma_pos == 10 || comma_pos != std::string::npos)
		{
			std::string date = line.substr(0, comma_pos);
			if (date.empty())
				throw DbFormat();
			std::string value = line.substr(comma_pos + 1);
			if (value.empty())
				throw DbFormat();
			float valueDb = std::stof(value);
			dbDateColumn.push_back(date);
			dbValueColumn.push_back(valueDb);
		}
		else
		{
			std::cerr << "Line " << line_count << std::endl;
			throw DbFormat();
		}
		line_count++;
	}
	std::vector<std::pair<std::string, float>> matrix(dbValueColumn.size());
	for (size_t i = 0; i < dbValueColumn.size(); i++)
	{
		matrix.push_back({dbDateColumn[i], dbValueColumn[i]});
	}
	if (print == true)
	{
		for (size_t i = 0; i < matrix.size(); ++i) // proof
		{
			std::cout << matrix[i].first << "," << matrix[i].second << std::endl;
		}
	}
	return (matrix);
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