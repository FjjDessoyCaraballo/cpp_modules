/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main(void)
{
	std::cout << "### CLAPTRAP ###" << std::endl;
	std::cout << std::endl;
	{
		ClapTrap clap("Clapper");
		std::string flap = "flapper";

		clap.attack(flap);
		clap.attack("brapper");
		clap.takeDamage(5);
		clap.beRepaired(5);
		clap.takeDamage(5);
		clap.takeDamage(5);
		std::cout << "It was at this moment that clap found out he was dead" << std::endl;
		clap.beRepaired(5);
	}
	return (0);
}