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
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
	private:
		std::string _target;
	public:	
		// constructor
		PresidentialPardonForm( std::string target );
		
		// destructor
		~PresidentialPardonForm();

		// canonical form
		PresidentialPardonForm( const PresidentialPardonForm& ref );
		PresidentialPardonForm &operator=( const PresidentialPardonForm& ref );

		// public methods
		void execute( const Bureaucrat& executor ) const;

		// getters
		std::string getTarget() const;

		// setters


		// exception

};