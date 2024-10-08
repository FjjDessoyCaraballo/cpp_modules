/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main()
{
	// little zombie and some loser created using stack to announce them
	Zombie zombie("aspargus");
	zombie.announce();
	randomChump("Marcos do Val");
	randomChump("Felix de Oliveira");
	// little zombie created using heap (newZombie function uses new)
	Zombie* zptr;
	zptr = newZombie("Bigus Dickus");
	zptr->announce();
	delete zptr;
	zptr = newZombie("Claudionor");
	zptr->announce();
	// shotgun the little zombie with delete
	// by shotguning, I mean we are effectively clearing the memory used by it
	delete zptr;
	return (0);
}
