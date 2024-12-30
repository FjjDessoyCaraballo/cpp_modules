/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm( std::string name, int16_t gradeSig, int16_t gradeExec ): _name(name), _signature(false), _gradeSignature(gradeSig), _gradeExecution(gradeExec) 
{
	if (gradeSig > 150 || gradeExec > 150)
		throw GradeTooLowException();
	if (gradeSig < 1 || gradeExec < 1)
		throw GradeTooHighException();
}

AForm::~AForm()
{
	std::cout << "AForm " << this->_name << " has been archived successfuly" << std::endl;
}

AForm::AForm( const AForm& ref ): _name(ref._name), _signature(ref._signature), _gradeSignature(ref._gradeSignature), _gradeExecution(ref._gradeExecution)
{
	std::cout << "AForm has been copied! Don't forget your change and to stamp your copy with Linda" << std::endl;
}

AForm &AForm::operator=( const AForm& ref )
{
	if (this != &ref)
		this->_signature = ref.getSignature();
	return (*this);
}

std::string AForm::getName() const
{
	return (this->_name);
}

int16_t	AForm::getExecutionGrade() const
{
	return (this->_gradeExecution);
}

int16_t AForm::getSignatureGrade() const
{
	return (this->_gradeSignature);
}

bool	AForm::getSignature() const
{
	return (this->_signature);
}

void	AForm::beSigned( Bureaucrat const &officer )
{
	if (officer.getGrade() <= this->getSignatureGrade())
		this->_signature = true;
}


const char*	AForm::GradeTooHighException::what() const noexcept
{
	return ("\e[0;31mThis Aform needs to go through the Department of Absurd Values!\e[0m");
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return ("\e[0;31mYou have no idea how bureaucracy works, do you? You need to sign a petititon with your local magistrate first, file in a OA51 with a city counselor, wait for 14 working days, get it stamped on the District Office (they only work from 10.00 to 11.00 on Wednesdays), and then schedule an appointment through our ridiculously slow website www.bureaucracy.com/appointments. The next possible appointment is in July 2035. Good evening and NEXT!\e[0m");
}

const char* AForm::AlreadySigned::what() const noexcept
{
	return ("\e[0;31mStop being silly. It is obvious that the document was already signed! Linda, escort the good sir out, please\e[0m");
}

const char* AForm::NotSigned::what() const noexcept
{
	return ("\e[0;31mStop being silly. It is obvious that the document was NOT signed! Linda, escort the good sir out, please\e[0m");
}

std::ostream &operator<<( std::ostream& other, const AForm& ref)
{
	std::cout << "Form " << ref.getName() << " created" << std::endl;
	std::cout << "Necessary grades" << std::endl;
	std::cout << "EXECUTION GRADE: " << ref.getExecutionGrade() << std::endl;
	std::cout << "SIGNATURE GRADE: " << ref.getSignatureGrade() << std::endl;
	return (other);
}