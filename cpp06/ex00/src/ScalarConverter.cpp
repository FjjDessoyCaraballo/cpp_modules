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
		bool isFloat = false;
		if (!str.empty() && str.back() == 'f')
		{
			isFloat = true;
			str.pop_back();
		}
		if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		{
			char c = str[0];
			std::cout << "char: " << c << std::endl;
			isChar = true;
		}
		else if (isFloat == true)
			std::cout << "char: '*'" << std::endl;
		else
			std::cout << "char: " << "impossible" << std::endl;
		
		char *end;
		errno = 0;
		if (isChar == false)
		{
			size_t decimalPos = str.find('.');

			int longIntValue;
			longIntValue = static_cast<int>(std::strtol(str.c_str(), &end, 10));
			if (longIntValue > INT_MAX)
				std::cout << "int: impossible" << std::endl;
			else if (decimalPos != std::string::npos)
			{
				std::string noDecimal = str.substr(0, decimalPos);
				longIntValue = std::strtol(noDecimal.c_str(), &end, 10);
				std::cout << "int: " << longIntValue << std::endl;
			}
			else if (*end == '\0' && errno == 0)
				std::cout << "int: " << longIntValue << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
		}
		else
			std::cout << "int: impossible" << std::endl;
		
		

		errno = 0;
		int floatValue;
		floatValue = static_cast<float>(std::strtof(str.c_str(), &end));
		if (floatValue > 0)
		{
			if (std::isinf(floatValue))
				std::cout << "double: +inf" << std::endl;
		}
		if (floatValue < 0)
		{
			if (std::isinf(floatValue))
				std::cout << "double: -inf" << std::endl;
		}
		if (*end == '\0' && errno == 0)
			std::cout << "float: " << floatValue << "f" << std::endl;
		else
			std::cout << "float: impossible" << std::endl;


		errno = 0;
		int doubleValue;
		doubleValue = static_cast<double>(std::strtod(str.c_str(), &end));
		if (doubleValue > 0)
		{
			if (std::isinf(doubleValue))
				std::cout << "double: +inf" << std::endl;
		}
		if (doubleValue < 0)
		{
			if (std::isinf(doubleValue))
				std::cout << "double: -inf" << std::endl;
		}
		if (std::isnan(doubleValue))
			std::cout << "double: nan" << std::endl;
		else if (*end == '\0' && errno == 0)
			std::cout << "double: " << doubleValue << std::endl;
		else
			std::cout << "double: impossible" << std::endl;
	} catch (const std::exception& e) 
	{
		std::cerr << "Blasphemous! " << e.what() << std::endl;
	}
}