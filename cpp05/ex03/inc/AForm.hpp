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

class AForm
{
	private:
		const std::string 	_name;
		bool				_signature;
		const int16_t		_gradeSignature;
		const int16_t		_gradeExecution;
	protected:
		// constructor
		AForm( std::string name, int16_t gradeS, int16_t gradeE );
		
	public:
		// destructor
		virtual ~AForm();

		// canonical Aform
		AForm( const AForm& ref );
		AForm &operator=( const AForm& ref);

		// public methods
		void	beSigned( Bureaucrat const &officer );
		virtual void execute( const Bureaucrat& executor ) const = 0;
		
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
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		class AlreadySigned : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
};

std::ostream &operator<<( std::ostream& other, const AForm& ref);