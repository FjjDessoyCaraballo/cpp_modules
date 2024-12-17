/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/Base.hpp"
#include "../inc/C.hpp"
#include "../inc/B.hpp"
#include "../inc/A.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>

static Base* Generate()
{
	int a = rand() % 3;

	if (a == 1)
		return (new A());
	else if (a == 2)
		return (new B());
	else if (a == 3)
		return (new C());
	else
	{
		std::cerr << "Something terribly wrong happened" << std::endl;
		return (NULL);
	}
}

static void identify(Base *p)
{

}

static void identify(Base &p)
{

}

int main(void)
{
	return (0);
}