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

PresidentialPardonForm::PresidentialPardonForm( std::string target ): AForm("PPF-A1", 25, 5)
{
	this->_target = target;
	std::cout << "Presidential Pardon Form for: " << this->getTarget() << " created" << std::endl;
	std::cout << "GRADES FOR " << this->getName() << ":" << std::endl;
	std::cout << "Execution: " << this->getExecutionGrade() << std::endl; 
	std::cout << "Signature: " << this->getSignatureGrade() << std::endl;  
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Form " << this->getName() << " has been archived successfuly" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& ref ): AForm(ref.getName() + "_copy", ref.getExecutionGrade(), ref.getSignatureGrade())
{
	this->_target = ref.getTarget();
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm& ref )
{
	if (this == &ref)
		return (*this);
	this->_target = ref._target;
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute( const Bureaucrat& executor ) const
{
	if (this->getSignature() == false)
		throw NotSigned();
	if ((this->getExecutionGrade() < executor.getGrade())
		&& (this->getSignatureGrade() < executor.getGrade()))
		throw GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}