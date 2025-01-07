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
	size_t line_count = 0;

	while (std::getline(file, line))
	{
		file_parse.push_back(line); // at this point we have the whole file in a container
		size_t comma_pos = line.find(',');
		if (comma_pos == 10 || comma_pos != std::string::npos)
		{
			
		}
		else
		{
			std::cerr << "Line " << line_count << std::endl;
			throw DbFormat();
		}
		line_count++;
	}
	// for (size_t i = 0; i < file_parse.size(); ++i) // proof
	// 	std::cout << file_parse[i] << std::endl;
	// for (size_t i = 0; i < file_parse.size(); ++i) // separate into two columns
	// {
	// 	std::string parse_line = file_parse[i];
	// 	if (parse_line.empty())
	// 		break ;
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
	return ("Format of database is incorrect")
}