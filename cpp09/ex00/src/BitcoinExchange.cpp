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
	this->_subdb.open(newdb, std::ios::in);
	if (!this->_subdb.is_open()) {
		throw MissingNewDb();
	}
	this->_filedb.open("./src/data.csv", std::ios::in);
	if (!this->_filedb.is_open()) {
		throw MissingDb();
	}
	setMatrix(this->_filedb);
	// setMatrix(this->_subdb);
}

Database::~Database()
{
	if (this->_filedb.is_open())
		this->_filedb.close();
	if (this->_subdb.is_open())
		this->_subdb.close();
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


void	Database::setMatrix( std::fstream &file )
{
	std::vector<std::string> file_parse;
	std::string line;
	size_t line_count = 0; // for throwing informative exceptions

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
			this->_dbDateColumn.push_back(date);
			this->_dbValueColumn.push_back(valueDb);
		}
		else
		{
			std::cerr << "Line " << line_count << std::endl;
			throw DbFormat();
		}
		line_count++;
	}
	this->_matrixDb.resize(_dbValueColumn.size());
	for (size_t i = 0; i < _dbValueColumn.size(); i++)
	{
		this->_matrixDb.push_back({_dbDateColumn[i], _dbValueColumn[i]});
	}
	// for (size_t i = 0; i < _matrixDb.size(); ++i) // proof
	// {
	// 	std::cout << _matrixDb[i].first << "," << _matrixDb[i].second << std::endl;
	// }
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