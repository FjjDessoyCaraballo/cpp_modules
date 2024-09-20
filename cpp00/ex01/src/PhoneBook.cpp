/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

Phonebook::Phonebook(void)
{
	this->_index = 0;
	std::cout << "Why do you need a phonebook in 2024?" << std::endl;
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
	std::string	str;

	if (!user_interface(this->_contacts))
	{
		std::cout << std::endl << "Phonebook is empty!" << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		std::cout << "Select an index: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
					this->_contacts[str[0] - 1 - '0'].get_firstname().size())
				break ;
		}
		if (str != "")
			std::cout << "Invalid index!" << std::endl;
	}
	if (!std::cin.eof())
		this->print(this->_contacts[str[0] - 1 - '0']);
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


std::string	space_out(int n)
{
	std::string	str;

	while (n--)
		str.append(" ");
	return (str);
}

std::string	max_width(std::string str, long unsigned max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

int	user_interface(Contact contacts[8])
{
	char		c;
	int			i;
	std::string	str;

	std::cout << " 	ʕっ•ᴥ•ʔっ 	ʕっ•ᴥ•ʔっ" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	c = '0';
	i = 0;
	while (++c <= '8')
	{
		if (contacts[c - 1 - '0'].get_firstname().size() && ++i)
		{
			str = c;
			str = max_width(str, 10);
			std::cout << "|" << space_out(10 - str.size()) << str;
			str = max_width(contacts[c - 1  - '0'].get_firstname(), 10);
			std::cout << "|" << space_out(10 - str.size()) << str;
			str = max_width(contacts[c - 1 - '0'].get_lastname(), 10);
			std::cout << "|" << space_out(10 - str.size()) << str;
			str = max_width(contacts[c - 1 - '0'].get_nickname(), 10);
			std::cout << "|" << space_out(10 - str.size()) << str;
			std::cout << "|" << std::endl;
		}
	}
	std::cout << " 	ʕっ•ᴥ•ʔっ 	ʕっ•ᴥ•ʔっ" << std::endl;
	return (i);
}