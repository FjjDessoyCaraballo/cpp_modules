/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     														* */
/*        --------/   														* */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{	
}

Contact::~Contact(void)
{
}

std::string	Contact::get_firstname(void) const
{
	return (this->_FirstName);
}

std::string Contact::get_lastname(void) const
{
	return (this->_LastName);
}

std::string Contact::get_nickname(void) const
{
	return (this->_Nickname);
}

std::string Contact::get_number(void) const
{
	return (this->_Number);	
}

std::string Contact::get_secret(void) const
{
	return (this->_Secret);
}

void Contact::set_firstname(std::string str)
{
	this->_FirstName = str;
}

void Contact::set_lastname(std::string str)
{
	this->_LastName = str;
}

void Contact::set_nickname(std::string str)
{
	this->_Nickname = str;
}

void Contact::set_number(std::string str)
{
	this->_Number = str;
}

void Contact::set_secret(std::string str)
{
	this->_Secret = str;
}