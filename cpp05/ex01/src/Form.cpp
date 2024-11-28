/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form( std::string name, int16_t gradeSig, int16_t gradeExec ): _name(name), _signature(false), _gradeSignature(gradeSig), _gradeExecution(gradeExec) 
{
	if (gradeSig > 150 || gradeExec > 150)
		throw GradeTooLowException();
	if (gradeSig < 1 || gradeExec < 1)
		throw GradeTooHighException();
	std::cout << "Form " << this->_name << " created" << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " has been archived successfuly" << std::endl;
}

Form::Form( const Form& ref ): _name(ref._name), _signature(ref._signature), _gradeSignature(ref._gradeSignature), _gradeExecution(ref._gradeExecution)
{
	std::cout << "Form has been copied! Don't forget your change and to stamp your copy with Linda" << std::endl;
}

Form &Form::operator=( const Form& ref )
{
	if (this != &ref)
		this->_signature = ref.getSignature();
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

int16_t	Form::getExecutionGrade() const
{
	return (this->_gradeExecution);
}

int16_t Form::getSignatureGrade() const
{
	return (this->_gradeSignature);
}

bool	Form::getSignature() const
{
	return (this->_signature);
}

void	Form::beSigned( Bureaucrat const &officer )
{
	if ((officer.getGrade() < this->getExecutionGrade()) && (officer.getGrade() < this->getSignatureGrade()))
		this->_signature = true;
}


const char*	Form::GradeTooHighException::what() const noexcept
{
	return ("\e[0;31mThis form needs to go through the Department of Absurd Values!\e[0m");
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return ("\e[0;31mYou have no idea how bureaucracy works, do you? You need to sign a petititon with your local magistrate first, file in a OA51 with a city counselor, wait for 14 working days, get it stamped on the District Office (they only work from 10.00 to 11.00 on Wednesdays), and then schedule an appointment through our ridiculously slow website www.bureaucracy.com/appointments. The next possible appointment is in July 2035. Good evening and NEXT!\e[0m");
}


std::ostream &operator<<( std::ostream& other, const Form& ref)
{
	std::cout << "Form " << ref.getName() << " created" << std::endl;
	std::cout << "Necessary grades" << std::endl;
	std::cout << "EXECUTION GRADE: " << ref.getExecutionGrade() << std::endl;
	std::cout << "SIGNATURE GRADE: " << ref.getSignatureGrade() << std::endl;
	return (other);
}