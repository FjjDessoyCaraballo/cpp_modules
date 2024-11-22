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
#include <cstdlib>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        try {
            for (int i = 0; argv[2][i]; i++) {
                if (!std::isdigit(argv[2][i]) && argv[2][i] != '-') {
                    throw std::invalid_argument("Grade must be a valid integer.");
                }
            }
			for (int i = 0; argv[3][i]; i++) {
                if (!std::isdigit(argv[3][i]) && argv[3][i] != '-') {
                    throw std::invalid_argument("Grade change must be a valid integer.");
                }
            }
            Bureaucrat officer(argv[1], std::stoi(argv[2]));
			int change_grade = std::stoi(argv[3]);
			if (change_grade == 0)
            	std::cout << officer << std::endl;
			else
			{
				officer.changeGrade(change_grade);
				std::cout << officer << std::endl;
			}
        }
        catch (const Bureaucrat::GradeTooHighException& error) {
            std::cerr << "Exception: " << error.what() << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException& error) {
            std::cerr << "Exception: " << error.what() << std::endl;
        }
        catch (const std::invalid_argument& error) {
            std::cerr << "Invalid input: " << error.what() << std::endl;
        }
        catch (const std::exception& error) {
            std::cerr << "Unknown exception: " << error.what() << std::endl;
        }
    }
    else
        std::cout << "Usage: " << argv[0] << " <name> <grade> <grade change>" << std::endl;
    return 0;
}
