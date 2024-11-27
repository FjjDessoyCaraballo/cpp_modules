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
		std::string	_name;
		int8_t		_gradeSignature;
		int8_t		_gradeExecution;
		bool		_signature;
	public:	
		// constructor
		ShrubberyCreationForm( std::string name );
		
		// destructor
		~ShrubberyCreationForm();

		// canonical form
		ShrubberyCreationForm( const ShrubberyCreationForm& ref );
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm& ref );

		// public methods
		void createTree( std::string& file );

		// getters


		// setters


		// exception

};