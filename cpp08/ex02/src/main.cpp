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
#include <exception>

int main(void)
{
	try
	{
		{
			std::cout << " ## TEST 1 ## " << std::endl;
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
		}
		{
			std::cout << std::endl;
			std::cout << " ## TEST 2: testing for more methods (empty() and swap()) ## " << std::endl;
			std::cout << std::endl;
			MutantStack<int> mstack1;
			if (mstack1.empty())
				std::cout << "We see this message if the stack 1 is empty after creation" << std::endl;
			mstack1.push(5);
			mstack1.push(17);
			MutantStack<int> mstack2;
			if (mstack2.empty())
				std::cout << "We see this message if the stack 2 is empty after creation" << std::endl;
			std::cout << std::endl;
			mstack2.push(55);
			mstack2.push(120);
			std::cout << "stack 1: " << mstack1.top() << std::endl;
			std::cout << "stack 2: " << mstack2.top() << std::endl;
			mstack1.swap(mstack2);
			std::cout << "stack 1: " << mstack1.top() << std::endl;
			std::cout << "stack 2: " << mstack2.top() << std::endl;
		}
		{
			std::cout << std::endl;
			std::cout << " ## TEST 3: testing for emplace() method using previous test ## " << std::endl;
			std::cout << std::endl;
			MutantStack<int> mstack1;
			if (mstack1.empty())
				std::cout << "We see this message if the stack 1 is empty after creation" << std::endl;
			mstack1.emplace(3);
			MutantStack<int> mstack2;
			if (mstack2.empty())
				std::cout << "We see this message if the stack 2 is empty after creation" << std::endl;
			mstack2.emplace(11); // if one desires, they can create a class to test this properly
			std::cout << std::endl;
			std::cout << "Before swap" << std::endl;
			std::cout << "stack 1: " << mstack1.top() << std::endl;
			std::cout << "stack 2: " << mstack2.top() << std::endl;
			mstack1.swap(mstack2);
			std::cout << std::endl;
			std::cout << "After swap" << std::endl;
			std::cout << "stack 1: " << mstack1.top() << std::endl;
			std::cout << "stack 2: " << mstack2.top() << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::flush;
		return (1);
	}
	return (0);
}