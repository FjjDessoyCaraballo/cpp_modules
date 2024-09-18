/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     														* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

Phonebook::Phonebook(void)
{
	this->_index = 0;
	std::cout << "Why do you need to a phonebook in 2024?" << std::endl;
	std::cout << "Whatever. Just add up to 8 contacts or type exit" << std::endl;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Why must you fail me so often?" << std::endl;
}

void	Phonebook::add(void)
{
	std::string str;

	str = "";
	if (!std::cin.eof() && str == "")
	{
		
	}	
}