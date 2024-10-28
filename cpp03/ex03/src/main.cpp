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
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"

int main(void)
{
	std::cout << "### CLAPTRAP ###" << std::endl;
	{
		ClapTrap clap("Clapper");
		std::string flap = "flapper";

		clap.attack(flap);
		clap.attack("brapper");
		clap.takeDamage(5);
		clap.beRepaired(5);
		clap.takeDamage(5);
		clap.takeDamage(5);
		// clap should be dead ):
		clap.beRepaired(5);
	}
	std::cout << "### SCAVTRAP ###" << std::endl;
	{
		ScavTrap scav("Scaver");

		scav.attack("bragger");
		scav.guardGate();
		scav.takeDamage(5);
		scav.beRepaired(5);
		scav.takeDamage(5);
		scav.takeDamage(5);
	}
	std::cout << "### FRAGTRAP ###" << std::endl;
	{
		FragTrap frag("Fragger");

		frag.attack("bragger");
		frag.takeDamage(75);
		frag.beRepaired(50);
		frag.takeDamage(25);
		frag.takeDamage(25);	
		frag.highFivesGuys();
	}
	std::cout << "### DIAMONDTRAP ###" << std::endl;
	{
		DiamondTrap diad("Swagger");
	}
	return (0);
}