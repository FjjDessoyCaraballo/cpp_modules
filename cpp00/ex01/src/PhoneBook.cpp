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
	if (this->_index > 7)
	{
		std::cout << "Haha! Overwritting your first contact. Who uses phonebooks in 2024?" << std::endl;
		std::cout << "First contact overwritten: " << this->_contacts[this->_index % 8].get_firstname() << std::endl;
		std::cout << "You can also just end your suffering by typing EXIT" << std::endl;
		std::cout << "All caps btw" << std::endl; 
	}
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter first name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_firstname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_lastname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter phone number: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_number(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter nickname: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_nickname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter secret (uhhh): ";
		if (std::getline(std::cin, str) && str != "")
		{
			this->_contacts[this->_index % 8].set_secret(str);
			std::cout << this->_contacts[this->_index % 8].get_firstname() << \ 
				" added. I hope you're happy with this mediocre result" << \ 
				std::endl;
		}
	}
	this->_index++;
}

void	Phonebook::search(void)
{
	std::string str;

	str = "";
	if ()

}

void	Phonebook::print(Contact contact)
{
	std::cout << "Hol' up m8..." << std::endl;
	if (!contact.get_firstname().size())
	{
		std::cout << "bad luck, mate" << std::endl;
		return ;
	}
	std::cout << "First name: " << contact.get_firstname() << std::endl;
	std::cout << "Last name: " << contact.get_lastname() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone Number: " << contact.get_number() << std::endl;
	std::cout << "Super secret: " << contact.get_secret() << std::endl;
}

