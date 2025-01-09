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
	static_cast<void>(ref);
}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter& ref )
{
	static_cast<void>(ref);
	return (*this);
}

bool ScalarConverter::isDigit( int c )
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool ScalarConverter::isChar( std::string str )
{
	if (str.length() == 1 && !isDigit(str[0]))
		return (true);
	return (false);
}
bool ScalarConverter::isInt( std::string str )
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (i == 0 && (str[0] == '-' || str[0] == '+'))
			continue ;
		if (!isDigit(str[i]))
			return (false);
	}
	return (true);
}
bool ScalarConverter::isFloat( std::string str )
{
	unsigned int len = str.length();
	if (str[len - 1] != 'f') // need to reassure that it is at the end
		return (false);
	bool comma = false;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (i == 0 && (str[0] == '-' || str[0] == '+'))
			continue ;
		if (str[i] == '.' && !comma)
		{
			comma = true;
			continue ;
		}
		if (str[i] == '.' && comma)
			return (false);
		if (!isDigit(str[i]))
			return (false);
	}
	return (true);
	
}
bool ScalarConverter::isDouble( std::string str )
{
	bool comma = false;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (i == 0 && (str[0] == '-' || str[0] == '+'))
			continue ;
		if (str[i] == '.' && !comma)
		{
			comma = true;
			continue ;
		}
		if (str[i] == '.' && comma)
			return (false);
		if (!isDigit(str[i]))
			return (false);
	}
	return (true);
}

void ScalarConverter::printChar( char c, bool print )
{
	if (print == true)
	{
		if (!std::isprint(c))
			std::cout << "char: non-displayable" << std::endl;
		std::cout << "char: " << c << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
}

void ScalarConverter::printInt( long n, bool print )
{
	if (print == true)
	{
		if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		{
			std::cout << "int: impossible" << std::endl;
			return ;
		}
			int res = static_cast<int>(n);
		std::cout << "int: " << res << std::endl;
	}
	else
		std::cout << "integer: impossible" << std::endl;
}

void ScalarConverter::printFloat( float nf, std::string str, bool print )
{
	if (print == true)
	{
		unsigned int set {1};
		unsigned int len;

		len = str.length();
		if (str[str.length() - 1] == 'f')
			len--;
		for (size_t i = 0; i < len; i++)
		{
			if (str[i] == '.')
				set = len - i - 1;
		}
		std::cout << "float: " << std::fixed << std::setprecision(set) << nf << "f" << std::endl;
	}
	else
	{
		std::cout << "float: impossible" << std::endl;
	}
}

void ScalarConverter::printDouble( double nd, std::string str, bool print )
{
	if (print == true)
	{
		unsigned int set {1};
		unsigned int len;

		len = str.length();
		if (str[str.length() - 1] == 'f')
			len--;
		for (size_t i = 0; i < len; i++)
		{
			if (str[i] == '.')
				set = len - i - 1;
		}
		std::cout << "double: " << std::fixed << std::setprecision(set) << nd << std::endl;
	}
	else
	{
		std::cout << "double: impossible" << std::endl;
	}
}

void	ScalarConverter::pseudoLiterals( std::string str )
{
	float	nf;
	double	nd;

	if (str == "+inf" || str == "+inff")
	{
		printChar(0, false);
		printInt(0, false);
		nf = std::numeric_limits<float>::infinity();
		std::cout << "float: " << nf << std::endl;
		nd = std::numeric_limits<double>::infinity();
		std::cout << "double: " << nd << std::endl;
		return ;
	}
	else if (str == "-inf" || str == "+inff")
	{
		printChar(0, false);
		printInt(0, false);
		nf = -std::numeric_limits<float>::infinity();
		std::cout << "float: " << nf << std::endl;
		nd = -std::numeric_limits<double>::infinity();
		std::cout << "double: " << nd << std::endl;
		return ;
	}
	else if (str == "nan" || str == "nanf")
	{
		printChar(0, false);
		printInt(0, false);
		nf = std::numeric_limits<float>::has_quiet_NaN;
		nd = std::numeric_limits<double>::has_quiet_NaN;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
}

void ScalarConverter::convert( std::string str )
{
	if (str == "+inf" || str == "-inf"
		|| str == "+inff" || str == "-inff" 
		|| str == "nan" || str == "nanf")
	{
		pseudoLiterals(str);
		return ;
	}

	long 	nl;
	float	nf;
	double	nd;
	enum type type = NONE;

	if (isChar(str))
		type = CHAR;
	else if (isInt(str))
		type = INT;
	else if (isFloat(str))
		type = FLOAT;
	else if (isDouble(str))
		type = DOUBLE;
	try
	{
		switch (type)
		{
			case CHAR:
			{
				printChar(str[0], true);
				nl = static_cast<int>(str[0]);
				printInt(nl, false);
				nf = static_cast<float>(str[0]);
				printFloat(nf, str, false);
				nd = static_cast<double>(str[0]);
				printDouble(nd, str, false);
				break ;
			}
			case INT:
			{
				nl = std::stol(str);
				printChar(0, false);
				printInt(nl, true);
				nf = static_cast<float>(nl);
				printFloat(nf, str, true);
				nd = static_cast<double>(nl);
				printDouble(nd, str, true);
				break ;
			}
			case FLOAT:
			{
				nf = std::stof(str);
				printChar(0, false);
				nl = static_cast<long>(nf);
				printInt(nl, true);
				printFloat(nf, str, true);
				nd = static_cast<double>(nf);
				printDouble(nd, str, true);
				break ;
			}
			case DOUBLE:
			{
				nd = std::stod(str);
				printChar(0, false);
				nl = static_cast<long>(nd);
				printInt(nl, true);
				nf = static_cast<float>(nd);
				printFloat(nf, str, true);
				printDouble(nd, str, true);			
				break ;
			}
			case NONE:
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				break ;
			}
		}
		
	} catch (const std::exception& e) 
	{
		std::cerr << "Blasphemous! " << e.what() << std::endl;
	}
}


// if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		// {
		// 	char c = str[0];
		// 	std::cout << "char: " << c << std::endl;
		// 	isChar = true;
		// }
		// else if (isFloat == true)
		// 	std::cout << "char: '*'" << std::endl;
		// else
		// 	std::cout << "char: " << "impossible" << std::endl;
		
		// char *end = {};
		// errno = 0;
		// if (isChar == false)
		// {
		// 	size_t decimalPos = str.find('.');

		// 	int longIntValue;
		// 	longIntValue = static_cast<int>(std::strtol(str.c_str(), &end, 10));
		// 	if (longIntValue > INT_MAX)
		// 		std::cout << "int: impossible" << std::endl;
		// 	else if (decimalPos != std::string::npos)
		// 	{
		// 		std::string noDecimal = str.substr(0, decimalPos);
		// 		longIntValue = std::strtol(noDecimal.c_str(), &end, 10);
		// 		std::cout << "int: " << longIntValue << std::endl;
		// 	}
		// 	else if (*end == '\0' && errno == 0)
		// 		std::cout << "int: " << longIntValue << std::endl;
		// 	else
		// 		std::cout << "int: impossible" << std::endl;
		// }
		// else
		// 	std::cout << "int: impossible" << std::endl;
		
		

		// errno = 0;
		// float floatValue;
		// floatValue = static_cast<float>(std::stof(str));
		// if (floatValue > 0)
		// {
		// 	if (std::isinf(floatValue))
		// 		std::cout << "double: +inf" << std::endl;
		// }
		// if (floatValue < 0)
		// {
		// 	if (std::isinf(floatValue))
		// 		std::cout << "double: -inf" << std::endl;
		// }
		// if (*end == '\0' && errno == 0)
		// 	std::cout << "float: " << floatValue << "f" << std::endl;
		// else
		// 	std::cout << "float: impossible" << std::endl;


		// errno = 0;
		// double doubleValue;
		// doubleValue = static_cast<double>(std::stod(str));
		// if (doubleValue > 0)
		// {
		// 	if (std::isinf(doubleValue))
		// 		std::cout << "double: +inf" << std::endl;
		// }
		// if (doubleValue < 0)
		// {
		// 	if (std::isinf(doubleValue))
		// 		std::cout << "double: -inf" << std::endl;
		// }
		// if (std::isnan(doubleValue))
		// 	std::cout << "double: nan" << std::endl;
		// else if (*end == '\0' && errno == 0)
		// 	std::cout << "double: " << doubleValue << std::endl;
		// else
		// 	std::cout << "double: impossible" << std::endl;