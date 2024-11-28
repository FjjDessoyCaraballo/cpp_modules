/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#pragma once

#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		// constructors
		Intern();
		
		// destructor
		~Intern();

		// canonical form
		Intern( const Intern& ref );
		Intern &operator=( const Intern& ref );

		// public methods
		AForm* makeForm( std::string form, std::string target );
		AForm* makePPF( std::string target );
		AForm* makeSCF( std::string target );
		AForm* makeRRF( std::string target );

		// exceptions
		class Exception: public std::exception
		{
			public:
				const char* what() const noexcept;
		};
};