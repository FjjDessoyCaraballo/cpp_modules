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

int main(int argc, char **argv)
{
	try
	{
		Form form1("AC404", 75, 75);
		Bureaucrat officer1("Bob", 32);
		Bureaucrat officer2("Will", 100);

		std::cout << officer1 << std::endl;
		std::cout << officer2 << std::endl;

		std::cout << form << std::endl;

		officer1.signForm(form1);
		officer2.signForm(form1);
	}	catch (const Bureaucrat::GradeTooHighException& error) {
		std::cerr << "Exception: " << error.what() << std::endl;
       }
	catch (const Bureaucrat::GradeTooLowException& error) {
		std::cerr << "Exception: " << error.what() << std::endl;
	}
	catch (const Form::GradeTooHighException& error) {
		std::cerr << "Exception: " << error.what() << std::endl;
	}
	catch (const Form::GradeToolowException& error) {
		std::cerr << "Exception: " << error.what() << std::endl;
	}
	catch (const std::invalid_argument& error) {
		std::cerr << "Invalid input: " << error.what() << std::endl;
	}
       catch (const std::exception& error) {
		std::cerr << "Unknown exception: " << error.what() << std::endl;
	}
	return (0);
}
