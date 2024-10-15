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
	ScavTrap scav("Scaver");

	scav.attack("bragger");
	scav.guardGate();
	scav.takeDamage(5);
	scav.beRepaired(5);
	scav.takeDamage(5);
	scav.takeDamage(5);
	return (0);
}