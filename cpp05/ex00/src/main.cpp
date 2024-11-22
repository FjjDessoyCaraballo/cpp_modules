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

// int main(void)
// {
// 	try
// 	{
// 		Bureaucrat	officer1("Bob", 151);
// 		Bureaucrat	officer2("Roger", 1);
		

// 		std::cout << officer1 << std::endl;
// 		std::cout << officer2 << std::endl;
		
// 		std::cout << std::endl;
// 		std::cout << "###################### CHANGING GRADES ######################" << std::endl;
// 		std::cout << std::endl;

// 		Bureaucrat	officer3("David", 50);
// 		std::cout << officer3 << std::endl;
// 		std::cout << "deducting 5 grade points to " << officer3.getName() << " which current grade is " << officer3.getGrade() << std::endl;
// 		officer3.changeGrade(-5);
// 		std::cout << officer3 << std::endl;
// 		std::cout << "Adding 5 grade points to " << officer3.getName() << " which current grade is " << officer3.getGrade() << std::endl;
// 		officer3.changeGrade(5);

// 		Bureaucrat	officer4("Wilson", 100);
// 		std::cout << officer4 << std::endl;
// 		std::cout << "Adding 0 grade points to " << officer4.getName() << " which current grade is " << officer4.getGrade() << std::endl;
// 		officer4.changeGrade(0);
// 		std::cout << officer4 << std::endl;

// 		std::cout << std::endl;
// 		std::cout << "###################### EXCEPTIONS! ######################" << std::endl;
// 		std::cout << std::endl;
// 		std::cout << "We are going to put grade over and under the limits 0 and >150" << std::endl;
// 		std::cout << std::endl;
		
// 		std::cout << std::endl;
// 		std::cout << officer2.getName() << " has " << officer2.getGrade() << " grade" << std::endl;
// 		std::cout << "We will deduct 2 points, which should be inadmissible" << std::endl;	
// 		officer2.changeGrade(-2);

// 		std::cout << std::endl;		
// 		std::cout << officer1.getName() << " has " << officer1.getGrade() << " grade" << std::endl;
// 		std::cout << "We will give it 3 points, which should be inadmissible" << std::endl;
// 		officer1.changeGrade(3);
// 	}
// 	catch (const Bureaucrat::GradeTooHighException& error) {
// 		std::cerr << "Exception: " << error.what() << std::endl;
// 	}
// 	catch (const Bureaucrat::GradeTooLowException& error) {
// 		std::cerr << "Exception: " << error.what() << std::endl;
// 	}
// 	catch (const std::exception& error) {
// 		std::cerr << "Unknown exception: " << error.what() << std::endl;
// 	}
// 	return (0);
// }

#include <cstdlib> // For std::isdigit
#include <cctype>  // For std::isdigit

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
