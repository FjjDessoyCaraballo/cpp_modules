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
#include "../inc/ScavTrap.hpp"

int main(void)
{
	std::cout << "### CLAPTRAP ###" << std::endl;
	std::cout << std::endl;
	{
		ClapTrap clap("Clapper");

		clap.attack("Flapper");
		clap.attack("Brapper");
		clap.takeDamage(50);
		clap.beRepaired(5);
		clap.takeDamage(5);
		clap.takeDamage(5);
		std::cout << "It was at this moment that clap found out he was dead" << std::endl;
		clap.beRepaired(5);
	}
	
	std::cout << std::endl;
	std::cout << "### SCAVTRAP ###" << std::endl;
	std::cout << std::endl;

	{
		ScavTrap scav("Scaver");

		scav.attack("bragger");
		scav.guardGate();
		scav.takeDamage(5);
		scav.beRepaired(5);
		scav.takeDamage(5);
		scav.takeDamage(5);
	}

	{
		std::cout << std::endl;
		ScavTrap scav("Scaver");
		ClapTrap clap("Clapper");
		scav.takeDamage(70);
		clap.takeDamage(70);
		std::cout << "Our heroes are mortally wounded! Are they going to recover?!" << std::endl;
		for (int i = 0; i < 50; i++)
		{
			scav.beRepaired(1);
			clap.beRepaired(1);
		}
		scav.guardGate();
		clap.attack("bag of rotten apples");
		std::cout << "is this the end for our heroes?" << std::endl;
		std::cout << std::endl;

	}
	{
		std::cout << std::endl;
		std::cout << "look out! Scaver is back! And he brought something!" << std::endl;
		std::cout << std::endl;
		ScavTrap scav("Scaver");
		ClapTrap clap("Clapper");

		std::cout << "Apparently he's going to attack a bag of rotten apples!" << std::endl;
		scav.attack("big bag of rotten apples");
		std::cout << "OMG THE ROTTEN APPLES ARE ATTACKING" << std::endl;
		scav.takeDamage(100);
		std::cout << "OMG!!11!1! SCAV IS DEAD!" << std::endl;
		scav.beRepaired(5);
		clap.attack("big bag of rotten apples");
		clap.takeDamage(100);
		clap.beRepaired(5);
		std::cout << "Seems like this is the end of our mighty Scaver and his friend Clapper" << std::endl;
	}
}