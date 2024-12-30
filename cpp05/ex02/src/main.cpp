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
		RobotomyRequestForm form3("Bill, the janitor Robotomization");
		PresidentialPardonForm form2("Bill's brother Pardon");
		ShrubberyCreationForm form1("./tree");
        Bureaucrat bob("Bob", 50);
        Bureaucrat rog("Roger", 5);
        Bureaucrat jef("Jeff", 148);

    try {
        std::cout << "\n### BOB FORMS ###\n\n";
        bob.signForm(form1);
        bob.executeForm(form1);
    } catch (const std::exception& error) {
        std::cerr << "Unhandled exception: " << error.what() << std::endl;
    }
    try {
        std::cout << "\n### ROGER FORMS ###\n\n";
        rog.signForm(form2);
        rog.executeForm(form2);
	} catch (const std::exception& error) {
        std::cerr << "Unhandled exception: " << error.what() << std::endl;
    }

    try {
        std::cout << "\n### JEFF FORMS ###\n\n";
		rog.signForm(form3);
		rog.executeForm(form3);
	} catch (const std::exception& error) {
        std::cerr << "Exception: " << error.what() << std::endl;
    }
	std::cout << std::endl;
	return (0);
}
