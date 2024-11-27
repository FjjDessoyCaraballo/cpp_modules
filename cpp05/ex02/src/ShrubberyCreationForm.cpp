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

std::string &PresidentialPardonForm::_name = "Presidential Pardon"

ShrubberyCreationForm::ShrubberyCreationForm( std::string const& target ): _gradeSignature(145), _gradeExecution(137), _signature(false)
{
	std::cout << "RobotomyRequestForm: " << this->getName() << " created" << std::endl;
	std::cout << "GRADES FOR " << this->getName() << ":" << std::endl;
	std::cout << "Execution: " << this->getExecutionGrade() << std::endl; 
	std::cout << "Signature: " << this->getSignatureGrade() << std::endl;  
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Form " << this->_name << " has been archived successfuly" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& ref )
{
	this->_name = ref.getName();
	this->_gradeSignature = ref.getSignatureGrade();
	this->_gradeExecution = ref.getExecutionGrade();
	this->_signature = ref.getSignature();
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm& ref )
{
	if (this == &ref)
		return (*this);
	this->_name = ref.getName();
	this->_gradeSignature = ref.getSignatureGrade();
	this->_gradeExecution = ref.getExecutionGrade();
	this->_signature = ref.getSignature();
	return (*this);
}

void	ShrubberyCreationForm::createTree( std::string& file )
{

	if (this->getSignature() == true)
	{
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
	std::cout << "Form is not signed! Visit Linda in HR and she will see you off" << std::endl;
}