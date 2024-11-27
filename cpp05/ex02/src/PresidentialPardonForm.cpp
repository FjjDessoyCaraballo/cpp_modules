/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(  ): _gradeSignature(25), _gradeExecution(5), _signature(false)
{
	std::cout << "RobotomyRequestForm: " << this->getName() << " created" << std::endl;
	std::cout << "GRADES FOR " << this->getName() << ":" << std::endl;
	std::cout << "Execution: " << this->getExecutionGrade() << std::endl; 
	std::cout << "Signature: " << this->getSignatureGrade() << std::endl;  
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Form " << this->_name << " has been archived successfuly" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& ref )
{
	this->_name = ref.getName();
	this->_gradeSignature = ref.getSignatureGrade();
	this->_gradeExecution = ref.getExecutionGrade();
	this->_signature = ref.getSignature();
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm& ref )
{
	if (this == &ref)
		return (*this);
	this->_name = ref.getName();
	this->_gradeSignature = ref.getSignatureGrade();
	this->_gradeExecution = ref.getExecutionGrade();
	this->_signature = ref.getSignature();
	return (*this);
}