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
#include "../inc/Form.hpp"

int main(void)
{
	try 
	{
			std::cout << std::endl;
			std::cout << "\e[0;31m### FIRST TEST ###\e[0m" << std::endl;
			std::cout << std::endl;
			std::cout << "\e[0;31m### CONSTRUCTORS ###\e[0m" << std::endl;
			std::cout << std::endl;
			Form form1("AC404", 75, 75);
			Bureaucrat officer1("Bob", 32);
			Bureaucrat officer2("Will", 100);
			std::cout << std::endl;
			std::cout << "\e[0;31m### OFFICERS ###\e[0m" << std::endl;
			std::cout << std::endl;
			std::cout << officer1 << std::endl;
			std::cout << officer2 << std::endl;
			std::cout << std::endl;
			std::cout << "\e[0;31m### FORMS ###\e[0m" << std::endl;
			std::cout << std::endl;
			std::cout << form1 << std::endl;
			std::cout << std::endl;
			std::cout << "\e[0;31m### FORM SIGNING ###\e[0m" << std::endl;
			std::cout << std::endl;
			officer1.signForm(form1);
			officer2.signForm(form1);
			std::cout << std::endl;
			std::cout << "\e[0;31m### DESTRUCTORS and/or EXCEPTIONS ###\e[0m" << std::endl;
			std::cout << std::endl;

				// std::cout << std::endl;
				// std::cout << "\e[0;31m### SECOND TEST ###\e[0m" << std::endl;
				// std::cout << std::endl;

				// std::cout << "\e[0;31m### CONSTRUCTORS ###\e[0m" << std::endl;
				// std::cout << std::endl;

				// Form form1("AC404", 75, 75);
				// Form form2("ZH88", 120, 120);
				// Bureaucrat officer1("Bob", 32);
				// Bureaucrat officer2("Will", 100);
				// std::cout << std::endl;

				// std::cout << "\e[0;31m### OFFICERS ###\e[0m" << std::endl;
				// std::cout << std::endl;

				// std::cout << officer1 << std::endl;
				// std::cout << officer2 << std::endl;

				// std::cout << std::endl;
				// std::cout << "\e[0;31m### FORMS ###\e[0m" << std::endl;
				// std::cout << std::endl;

				// std::cout << form1 << std::endl;
				// std::cout << form2 << std::endl;

				// std::cout << std::endl;

				// std::cout << "\e[0;31m### FORM SIGNING ###\e[0m" << std::endl;
				// std::cout << std::endl;

				// officer1.signForm(form1);
				// officer2.signForm(form2);
				// std::cout << std::endl;

				// std::cout << "\e[0;31m### DESTRUCTORS and/or EXCEPTIONS ###\e[0m" << std::endl;
				// std::cout << std::endl;
		} catch (const std::exception &e) {
        	std::cerr << "Unhandled Exception: " << e.what() << std::endl;
        	return (1);
		}
	}
	return (0);
}
