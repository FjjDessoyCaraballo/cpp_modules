/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern has been hired" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern has been fired for giggles" << std::endl;
}

Intern::Intern( const Intern& ref )
{
	std::cout << "Look, Linda, this intern thinks he's special! You're all the same!" << std::endl;
	static_cast<void>(ref);
}

Intern &Intern::operator=( const Intern& ref)
{
	static_cast<void>(ref);
	return (*this);
}


AForm*	Intern::makePPF( std::string target )
{
	std::cout << "Intern has created a Presidential Pardon Form" << std::endl;
	AForm *ppf = new PresidentialPardonForm(target);
	return (ppf);
}

AForm*	Intern::makeRRF( std::string target )
{
	std::cout << "Intern has created a Robotomy Request Form" << std::endl;
	AForm *rrf = new RobotomyRequestForm(target);
	return (rrf);
}

AForm*	Intern::makeSCF( std::string target )
{
	std::cout << "Intern has created a Shrubbery Creation Form" << std::endl;
	AForm *scf = new ShrubberyCreationForm(target);
	return (scf);
}

AForm*	Intern::makeForm( std::string form, std::string target )
{
	typedef AForm* (Intern::*FormFinder)(std::string);
	FormFinder	forms[3] = { &Intern::makeSCF, &Intern::makePPF, &Intern::makeRRF };
	std::string formNames[3] = { "shrubbery creation", "presidential pardon", "robotomy request" };
	AForm *formReturn = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (form == formNames[i])
			formReturn = ((this->*forms[i])(target));
	}
	if (!formReturn)
		throw (Intern::Exception());
	return (formReturn);
}

const char *Intern::Exception::what() const noexcept
{
	return ("The intern said you were asking for some weird forms. Now, we do love to have a laugh at them, but we disencourage the general public of taking such actions towards our poorly paid interns. Why? Who are you now? Linda, get him out of here");
}