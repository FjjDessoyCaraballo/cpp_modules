/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int	harl_level(char *complaint)
{
	std::string levels[4] = { "debug", "info", "warning", "error" };
	std::string complaintStr = complaint;

	int i = 0;
	while (i < 4)
	{
		if (levels[i].compare(complaintStr) == 0)
			return (i);
		i++;
	}
	return (0);
}

void switch_harl(char *argv, Harl &harl)
{
	switch(harl_level(argv))
	{
		case 3:
			harl.complain("error");
		case 2:
			harl.complain("warning");
		case 1:
			harl.complain("info");
		case 0:
			harl.complain("debug");
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Harl harl;
		switch_harl(argv[1], harl);
	}
	else
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	return (0);
}
