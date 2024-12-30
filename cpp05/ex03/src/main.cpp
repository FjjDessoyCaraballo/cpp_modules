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
#include <memory>

int main() {
    try {
        Intern asswipe;
        Bureaucrat bob("Bob", 75);
        Bureaucrat rog("Roger", 5);
        Bureaucrat jef("Jeff", 148);

        std::unique_ptr<AForm> form3(asswipe.makeForm("presidential pardon", "Enricsonson"));
        std::unique_ptr<AForm> form2(asswipe.makeForm("robotomy request", "Steve"));
        std::unique_ptr<AForm> form1(asswipe.makeForm("shrubbery creation", "bugger"));

        std::cout << "\n### BOB FORMS ###\n\n";
        bob.signForm(*form1);
        bob.executeForm(*form1);

        std::cout << "\n### ROGER FORMS ###\n\n";
        rog.signForm(*form2);
        rog.executeForm(*form2);

        std::cout << "\n### JEFF FORMS ###\n\n";
		rog.signForm(*form3);
		rog.executeForm(*form3);
        // jef.signForm(*form3);
        // jef.executeForm(*form3); // jeff can't execute, it's going to throw an exception

		bob.signForm(*form2);
		std::cout << std::endl;
		std::cout << std::endl;
    } catch (const std::exception& error) {
        std::cerr << "Unhandled exception: " << error.what() << std::endl;
    }
    return 0;
}

