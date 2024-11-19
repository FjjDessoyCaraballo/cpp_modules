/* ************************************************************************** */
/*  ROFL:ROFL:ROFL:ROFL 													* */
/*          _^___      														* */
/* L     __/   [] \    														* */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					* */
/* L      \________]  					by fdessoy-							* */
/*         I   I     			(fdessoy-@student.hive.fi)					* */
/*        --------/   														* */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/AAnimal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"

int main(void)
{
    std::cout << "########################################################" << std::endl;
    std::cout << "###################### EX02 ############################" << std::endl;
    std::cout << "########################################################" << std::endl;
	{
		// the below two next lines will not compile if uncommented
		// AAnimal animal; // proof of impossibility to instantiate
		// animal.makeSound();
		const AAnimal* i = new Dog(); // polymorphic instantiation
        const AAnimal* j = new Cat(); // polymorphic instantiation

		i->makeSound();
		j->makeSound();

		std::cout << "'i' is a " << i->getType() << std::endl;
		std::cout << "'j' is a " << j->getType() << std::endl;


		delete i;
		delete j;

	}
    return 0;
}
