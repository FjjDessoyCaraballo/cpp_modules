/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/MutantStack.hpp"
#include <iostream>
#include <stack>

int main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl; // this should  output 17 as the first line
	mstack.pop();
	std::cout << mstack.size() << std::endl; // this should output 1 as we popped the size to one
	mstack.push(3);
	mstack.push(5);
	mstack.push(737); // here size is 3 and top is 737
	//[...]
	mstack.push(0); // here size is 4 and top is 0
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl; // output: 5,3,5,737,0
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << s.top() << std::endl;
	return (0);
}