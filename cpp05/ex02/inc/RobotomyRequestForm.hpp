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

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_name;
		int8_t		_gradeSignature;
		int8_t		_gradeExecution;
		bool		_signature;
	public:	
		// constructor
		RobotomyRequestForm( std::string name );
		
		// destructor
		~RobotomyRequestForm();

		// canonical form
		RobotomyRequestForm( const RobotomyRequestForm& ref );
		RobotomyRequestForm &operator=( const RobotomyRequestForm& ref );

		// public methods
		void performRobotomy( Bureaucrat const &officer );

		// getters


		// setters


		// exception

};