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
#include <iostream>
#include <random>
#include <stdexcept>

static Base* generate()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 3);
	int a = dist(gen);

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

static void identify(Base* p)
{
	try {
	if (dynamic_cast<C*>(p))
		std::cout << "It's a C pointer!" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "It's a A pointer!" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It's a B pointer!" << std::endl;
	if (p == NULL) {
		std::cerr << "Error: could not cast" << std::endl;
	}
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

static void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "T'was a type base reference to A!" << std::endl;
		return ;
	} catch (std::exception &e) {
		// std::cerr << "Exception for A: " << e.what() << std::endl;
	}
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "T'was a type base reference to B!" << std::endl;
		return ;
	} catch (std::exception &e) {
		// std::cerr << "Exception for B: " << e.what() << std::endl;
	}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "T'was a type base reference to C!" << std::endl;
		return ;
	} catch (std::exception& e) {
		// std::cerr << "Exception for C: " << e.what() << std::endl;
	}

	std::cerr << "Error: could not identify type" << std::endl;
}

int main(void) 
{
	std::cout << std::endl;
	std::cout << " ### TEST 1 ###" << std::endl;
	std::cout << std::endl;

	Base* test1 = generate();
	identify(test1);
	identify(*test1);

	std::cout << std::endl;
	std::cout << " ### TEST 2 ###" << std::endl;
	std::cout << std::endl;

	Base* test2 = generate();
	identify(test2);
	identify(*test2);

	std::cout << std::endl;
	std::cout << " ### TEST 3 ###" << std::endl;
	std::cout << std::endl;

	Base* test3 = generate();
	identify(test3);
	identify(*test3);

	std::cout << std::endl;
	std::cout << " ### TEST FOR NULL ### " << std::endl;
	std::cout << std::endl;

	Base* unknown = nullptr;
	identify(unknown);
	identify(*unknown);

	
	delete test1;
	delete test2;
	delete test3;
	return (0);
}
