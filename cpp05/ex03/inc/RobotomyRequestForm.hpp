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
		std::string _target;
	public:	
		// constructor
		RobotomyRequestForm( std::string target );
		
		// destructor
		~RobotomyRequestForm();

		// canonical form
		RobotomyRequestForm( const RobotomyRequestForm& ref );
		RobotomyRequestForm &operator=( const RobotomyRequestForm& ref );

		// public methods
		void performRobotomy( Bureaucrat const &officer );
		void execute( const Bureaucrat& executor ) const;

		// getters
		std::string getTarget() const;

		// setters


		// exception

};