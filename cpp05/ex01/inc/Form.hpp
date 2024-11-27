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

class Bureaucrat;

class Form
{
	private:
		const std::string 	_name;
		bool				_signature;
		const int16_t		_gradeSignature;
		const int16_t		_gradeExecution;
	public:
		// constructor
		Form( std::string name, int16_t gradeS, int16_t gradeE );
		
		// destructor
		~Form();

		// canonical form
		Form( const Form& ref );
		Form &operator=( const Form& ref);

		// public methods
		void	beSigned( Bureaucrat const &officer );
		
		// getters
		std::string	getName() const;
		int16_t		getSignatureGrade() const;
		int16_t		getExecutionGrade() const;
		bool		getSignature() const;

		// execeptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		class GradeToolowException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
};

std::ostream &operator<<( std::ostream& other, const Form& ref);