/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(  ): _gradeSignature(72), _gradeExecution(45), _signature(false)
{
	std::cout << "RobotomyRequestForm: " << this->getName() << " created" << std::endl;
	std::cout << "GRADES FOR " << this->getName() << ":" << std::endl;
	std::cout << "Execution: " << this->getExecutionGrade() << std::endl; 
	std::cout << "Signature: " << this->getSignatureGrade() << std::endl;  
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Form " << this->_name << " has been archived successfuly" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& ref )
{
	this->_name = ref.getName();
	this->_gradeSignature = ref.getSignatureGrade();
	this->_gradeExecution = ref.getExecutionGrade();
	this->_signature = ref.getSignature();
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm& ref )
{
	if (this == &ref)
		return (*this);
	this->_name = ref.getName();
	this->_gradeSignature = ref.getSignatureGrade();
	this->_gradeExecution = ref.getExecutionGrade();
	this->_signature = ref.getSignature();
	return (*this);
}