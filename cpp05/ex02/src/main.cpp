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
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

int main(void)
{
	{
		{
			std::cout << " ### CONSTRUCTORS ### " << std::endl;
			RobotomyRequestForm form1("Bill, the janitor Robotomization");
			std::cout << std::endl;
			PresidentialPardonForm form2("Bill's brother Pardon");
			std::cout << std::endl;
			ShrubberyCreationForm form3("./tree");
			std::cout << std::endl;
			Bureaucrat Bob("Bob, the builder", 75);

			Bureaucrat Steve("Steve Seagull", 149);

			Bureaucrat John("John Johnatan Johnson", 30);

			Bureaucrat Gerard("Gerard, the very french guy", 2);
			std::cout << std::endl;
			std::cout << std::endl;
			
			std::cout << " ### BOB FORM EXECUTIONS ###" << std::endl;
			std::cout << " BOB SHOULD BE ABLE TO EXECUTE A SCF-VB420 ";
			
			std::cout << std::endl;
			Bob.executeForm(form1);
			std::cout << std::endl;
			Bob.executeForm(form2);
			std::cout << std::endl;
			Bob.executeForm(form3);
			std::cout << std::endl;
			
			std::cout << " ### STEVE FORM EXECUTIONS ###" << std::endl;
			std::cout << " STEVE SHOULDN'T BE ABLE TO EXECUTE ANYTHING " << std::endl;
			
			std::cout << std::endl;
			Steve.executeForm(form1);
			std::cout << std::endl;
			Steve.executeForm(form2);
			std::cout << std::endl;
			Steve.executeForm(form3);
			std::cout << std::endl;
			
			std::cout << " ### JOHN FORM EXECUTIONS ###" << std::endl;
			std::cout << " JOHN SHOULD BE ABLE TO EXECUTE A SCF-VB420 AND RRF-C66" << std::endl;
			
			std::cout << std::endl;
			John.executeForm(form1);
			std::cout << std::endl;
			John.executeForm(form2);
			std::cout << std::endl;
			John.executeForm(form3);
			std::cout << std::endl;
			
			std::cout << " ### GERARD FORM EXECUTIONS ###" << std::endl;
			std::cout << " GERARD SHOULD BE ABLE TO EXECUTE THEM ALL " << std::endl;
			
			std::cout << std::endl;
			Gerard.executeForm(form1);
			std::cout << std::endl;
			Gerard.executeForm(form2);
			std::cout << std::endl;
			Gerard.executeForm(form3);
			std::cout << std::endl;
			std::cout << std::endl;

		}
	}
	return (0);
}
