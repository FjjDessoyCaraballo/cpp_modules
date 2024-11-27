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
		std::string	_name;
		int8_t		_gradeSignature;
		int8_t		_gradeExecution;
		bool		_signature;
	public:	
		// constructor
		PresidentialPardonForm( std::string name );
		
		// destructor
		~PresidentialPardonForm();

		// canonical form
		PresidentialPardonForm( const PresidentialPardonForm& ref );
		PresidentialPardonForm &operator=( const PresidentialPardonForm& ref );

		// public methods
		void pardonTarget( Bureaucrat const &officer );

		// getters


		// setters


		// exception

};