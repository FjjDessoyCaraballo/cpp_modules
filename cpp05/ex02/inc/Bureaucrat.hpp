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
#include <stdexcept>

class AForm;

class	Bureaucrat
{
	private:
		const std::string	_name;
		int16_t				_grade;
	public:
		// constructor
		Bureaucrat( std::string name, int grade );
		
		// destructor
		~Bureaucrat();

		// Canonical Form
		Bureaucrat( const Bureaucrat& ref );
		Bureaucrat &operator=( const Bureaucrat& ref );

		// public methods
		void		changeGrade( int8_t grade );
		void		signForm(AForm &form);
		void 		executeForm( AForm const &form );

		// getters
		std::string	getName() const;
		int16_t		getGrade() const;

		// exceptions
		class	GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
};

std::ostream &operator<<( std::ostream& other, const Bureaucrat& ref );