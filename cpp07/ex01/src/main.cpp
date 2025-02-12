/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/iter.hpp"

#include <iostream>
#include <cstdint>
#include <string>
#include <cctype> 

void increment(int& x) {
    x++;
}

void doubleValue(double& x) {
    x *= 2;
}

void toUpperCase(char& c) {
    c = std::toupper(c);
}

void appendExclamation(std::string& str) {
    str += "!";
}

int main() {
	int numbers[] = {1, 2, 3, 4, 5};
	uint32_t len = sizeof(numbers) / sizeof(numbers[0]);
	iter(numbers, len, increment);
	std::cout << "Incremented integers: ";
	for (uint32_t i = 0; i < len; i++)
	    std::cout << numbers[i] << " ";
	std::cout << std::endl;

	double decimals[] = {1.1, 2.2, 3.3, 4.4};
	len = sizeof(decimals) / sizeof(decimals[0]);
	iter(decimals, len, doubleValue);
	std::cout << "Doubled floats: ";
	for (uint32_t i = 0; i < len; i++)
	    std::cout << decimals[i] << " ";
	std::cout << std::endl;

	char letters[] = {'a', 'b', 'c', 'd'};
	len = sizeof(letters) / sizeof(letters[0]);
	iter(letters, len, toUpperCase);
	std::cout << "Uppercase letters: ";
	for (uint32_t i = 0; i < len; i++)
	    std::cout << letters[i] << " ";
	std::cout << std::endl;

	std::string words[] = {"hello", "world", "test"};
	len = sizeof(words) / sizeof(words[0]);
	iter(words, len, appendExclamation);
	std::cout << "Modified strings: ";
	for (uint32_t i = 0; i < len; i++)
	    std::cout << words[i] << " ";
	std::cout << std::endl;

	int emptyArray[0];
	iter(emptyArray, 0, increment);
	std::cout << "Empty array test passed (no output expected).\n";

	return 0;
}
