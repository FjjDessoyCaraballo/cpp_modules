/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): AForm("SCF-VB420", 145, 137)
{
	this->_target = target;
	std::cout << "Shrubbery Creation Form for: " << this->getTarget() << " created" << std::endl;
	std::cout << "GRADES FOR " << this->getName() << ":" << std::endl;
	std::cout << "Execution: " << this->getExecutionGrade() << std::endl; 
	std::cout << "Signature: " << this->getSignatureGrade() << std::endl;  
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Form " << this->getName() << " has been archived successfuly" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& ref ): AForm(ref.getName() + "_copy", 145, 137)
{
	this->_target = ref.getTarget();
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm& ref )
{
	if (this == &ref)
		return (*this);
	this->_target = ref.getTarget();
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute( const Bureaucrat& executor ) const
{
	if (this->getSignature() == true)
		throw AlreadySigned();
	if ((this->getExecutionGrade() < executor.getGrade())
		&& (this->getSignatureGrade() < executor.getGrade()))
		throw GradeTooLowException();
	std::string		file = this->getTarget();
	std::ofstream	outfile(file + "_shrubbery");
	if (!outfile)
	{
		std::cout << "Error: could not open file " << file << std::endl;
		return ;
	}
	outfile << "         _-_         " << std::endl;
	outfile << "      /~~   ~~\\      " << std::endl;
	outfile << "   /~~         ~~\\   " << std::endl;
	outfile << "  {               }  " << std::endl;
	outfile << "   \\  _-     -_  /   " << std::endl;
	outfile << "     ~  \\\\ //  ~     " << std::endl;
	outfile << "          | |         " << std::endl;
	outfile << "          | |         " << std::endl;
	outfile << "         // \\\\        " << std::endl;
}
