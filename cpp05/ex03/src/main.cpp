/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

int main(void)
{
	{
		{
			Intern asswipe;

			try
			{
				asswipe.makeForm("presidential pardon", "Bob");
				asswipe.makeForm("robotomy request", "Steve");
				asswipe.makeForm("shrubbery creation", "./bugger");
				asswipe.makeForm("aaaaa", "Dale");
			} catch (const Intern::Exception& error) {
				std::cerr << "Exception: " << error.what() << std::endl;
			}
		}
	}
	return (0);
}
