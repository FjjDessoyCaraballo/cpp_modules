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
#include <random>

RobotomyRequestForm::RobotomyRequestForm( std::string target ): AForm("RRF-C66", 72, 45)
{
	this->_target = target;
	std::cout << "RobotomyRequestForm: " << this->getName() << " created for target " << this->getTarget() << std::endl;
	std::cout << "GRADES FOR " << this->getName() << ":" << std::endl;
	std::cout << "Execution: " << this->getExecutionGrade() << std::endl; 
	std::cout << "Signature: " << this->getSignatureGrade() << std::endl;  
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Form " << this->getName() << " has been archived successfuly" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& ref ): AForm(ref.getName() + "_copy", 72, 45)
{
	this->_target = ref.getTarget();
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm& ref )
{
	if (this == &ref)
		return (*this);
	this->_target = ref.getTarget();
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute( const Bureaucrat& executor ) const
{
	if (this->getSignature() == true)
		throw AlreadySigned();
	if ((this->getExecutionGrade() < executor.getGrade())
		&& (this->getSignatureGrade() < executor.getGrade()))
		throw GradeTooLowException();
  	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, 1);
	int randomNumber = dist(gen);

	std::cout << "Linda will perform the robotomization now! Keep still!" << std::endl;
	std::cout << "BZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ ** drill noises **" << std::endl;
	std::cout << "Ok, Linda, lets see if this was better than last time" << std::endl;
	if (randomNumber == 1)
		std::cout << "Successfully robotomized " << this->getTarget() << std::endl;
	else
		std::cout << "Failed to robotomize " << this->getTarget() << std::endl;
}