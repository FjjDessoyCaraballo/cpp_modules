/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     														* */
/*        --------/   														* */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

/**
 * When doing a class we should set the private and public variables.
 * 
 * Private variables will be like const variables in C, in which they do not
 * change their values, ceteris paribus. The underscore is a non-mandatory
 * convention to differentiate private variables from the public variables
 * in calls.
 * 
 * Public variables are variables that can be used and have their values changed.
 * 
 * In the public variables we will see the first two variables with the same
 * name of the class, but in format of a C function. The first one what is
 * commonly called as a contructor, while the second one, with the tilde, is 
 * what is commonly referenced as a destructor.
*/
class Contact
{
	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_Nickname;
		std::string	_Number;
		std::string _Secret;
	public:
		Contact(void);
		~Contact(void);
		// getters
		std::string	get_firstname(void) const;
		std::string	get_lastname(void) const;
		std::string	get_nickname(void) const;
		std::string	get_number(void) const;
		std::string get_secret(void) const;
		// setters
		void		set_firstname(std::string str);
		void		set_lastname(std::string str);
		void		set_nickname(std::string str);
		void		set_number(std::string str);
		void		set_secret(std::string str);
};

#endif