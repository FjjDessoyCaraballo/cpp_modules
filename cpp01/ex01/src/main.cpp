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
	int 	size;
	Zombie	*zptr;
	int 	i;

	size = 5;
	zptr = zombieHorde(size, "Sir Chuckalot");
	for (i = 0; i < size; i++)
	{
		zptr->announce();
	}
	delete [] zptr;
	return (0);
}
