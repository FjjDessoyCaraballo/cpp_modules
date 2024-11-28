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

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;
	public:	
		// constructor
		ShrubberyCreationForm( std::string target );
		
		// destructor
		~ShrubberyCreationForm();

		// canonical form
		ShrubberyCreationForm( const ShrubberyCreationForm& ref );
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm& ref );

		// public methods
		void createTree( std::string& file );
		void execute( const Bureaucrat& executor ) const;

		// getters
		std::string getTarget() const;

		// setters


		// exception

};