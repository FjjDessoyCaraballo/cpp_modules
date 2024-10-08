/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

/**
 * Create a program that takes three parameters in the following order: a 
 * filename and two strings, s1 and s2. It will open the file <filename> 
 * and copies its content into a new file <filename>.replace, replacing 
 * every occurrence of s1 with s2.
 * 
 * @param firstParamter will be the <filename>
 * @param secondParameter will be s1 which will be replaced
 * @param thirdParameter will be s2 the new string in <filename>
 * 
 * The output will be a new file with a new file with s1's ocurrences being
 * replaced by s2's.
*/
int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream inputFile(argv[1]);
		if (!inputFile)
		{
			std::cerr << "Could not open the file:" << std::endl;
			std::cerr << "Possible reasons: (1) Non-existing file; ";
			std::cerr << "(2) Wrong permissions; ";
			std::cerr << "(3) You are in a dream, wake up!" << std::endl;
			return (2);
		}
		std::string originalFilename = argv[1];
		std::string buffer;
		std::string newContent; 
		while (std::getline(inputFile, buffer))
		{
			std::size_t position = buffer.find(argv[2]);
			if (position != std::string::npos)
			{
				buffer.erase(position, std::string(argv[2]).length());
				buffer.insert(position, argv[3]);
			}
			newContent += buffer + "\n";
		}
		inputFile.close();
		std::string newFilename = originalFilename + ".replace";
		std::ofstream outputFile(newFilename.c_str());
		if (!outputFile)
		{
			std::cerr << "Error: something magical happened. Not good tho" << std::endl;
			return (2);
		}
		outputFile << newContent;
		outputFile.close();
	}
	else
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}
	return (0);
}
