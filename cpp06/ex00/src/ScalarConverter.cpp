/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter& ref )
{
	(void)ref;
}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter& ref )
{
	(void)ref;
	return (*this);
}

void ScalarConverter::convert( std::string str )
{
	try
	{
		bool isChar = false;
		if (!str.empty() && str.back() == 'f')
			str.pop_back();
		if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		{
			char c = str[0];
			std::cout << "char: " << c << std::endl;
			isChar = true;
		}
		else
			std::cout << "char: " << "impossible" << std::endl;
		
		char *end;
		errno = 0;
		if (isChar == false)
		{
			size_t decimalPos = str.find('.');

			long longIntValue = std::strtol(str.c_str(), &end, 10);
			if (decimalPos != std::string::npos)
				std::cout << "int: " << str.substr(0, decimalPos) << std::endl;
			else if (*end == '\0' && errno == 0)
				std::cout << "int: " << longIntValue << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
		}
		// else
		// 	std::cout << "int: impossible" << std::endl;

		errno = 0;
		float floatValue = std::strtof(str.c_str(), &end);

		if (*end == '\0' && errno == 0)
			std::cout << "float: " << floatValue << "f" << std::endl;
		else
			std::cout << "float: impossible" << std::endl;

		errno = 0;
		double doubleValue = std::strtod(str.c_str(), &end);
		if (*end == '\0' && errno == 0)
			std::cout << "double: " << doubleValue << std::endl;
		else
			std::cout << "double: impossible" << std::endl;
	} catch (const std::exception& e) 
	{
		std::cerr << "Blasphemous! " << e.what() << std::endl;
	}
}