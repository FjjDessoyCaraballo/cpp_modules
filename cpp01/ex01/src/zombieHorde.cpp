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

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie	*horde;
	int		i;

	horde = new Zombie[N];
	for (i = 0; N > i; i++)
		horde[i].zombieName(name);
	return (horde);
}
