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
#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"

int main(void)
{
	// std::cout << "########################################################" << std::endl;
	// std::cout << "###################### EX01 ############################" << std::endl;
	// std::cout << "########################################################" << std::endl;
	// {
	// 	const Animal* meta = new Animal();
	// 	const Animal* j = new Dog();
	// 	const Animal* i = new Cat();

	// 	std::cout << j->getType() << " " << std::endl;
	// 	std::cout << i->getType() << " " << std::endl;

	// 	i->makeSound();
	// 	j->makeSound();
	// 	meta->makeSound();
	// 	std::cout << std::endl;

	// 	delete	meta;
	// 	delete	i;
	// 	delete	j;
	// }
	// {
	// 	const WrongAnimal* meta = new WrongAnimal();
	// 	const WrongAnimal* j = new WrongCat();

	// 	std::cout << j->getType() << std::endl;
	// 	std::cout << meta->getType() << std::endl;
 
	// 	j->makeSound();
	// 	meta->makeSound();
	// 	std::cout << std::endl;

	// 	delete	j;
	// 	delete	meta;
	// }
    std::cout << "########################################################" << std::endl;
    std::cout << "###################### EX02 ############################" << std::endl;
    std::cout << "########################################################" << std::endl;
    {
        const Animal* i = new Dog();
        const Animal* j = new Cat();

        delete i;
        delete j;
    }
    {
		std::cout << "DEEP COPY TEST" << std::endl;
		Dog princess;
		Cat butcher;
		Dog& princess_REF = princess;
		Cat& butcher_REF = butcher;

		std::cout << std::endl;

		Dog princess_copy(princess);
		Cat butcher_copy(butcher);
		Dog& princess_copy_REF = princess_copy;
		Cat& butcher_copy_REF = butcher_copy;
		
		std::cout << "COMPARISON" << std::endl;
		
		princess.compare(princess_REF);
		butcher.compare(butcher_REF);
		princess.compare(princess_copy_REF);
		butcher.compare(butcher_copy_REF);
		std::cout << std::endl;
    }
	std::cout << std::endl;
	{
		std::cout << "THOUGHTS TEST" << std::endl;
	
		Dog princess;
		Cat butcher;
	
		std::cout << std::endl;
		std::cout << "Princess, which is a " << princess.getType() << " thinks that " << princess.getIdeas(1) << std::endl;
		std::cout << "Butcher, which is a " << butcher.getType() << " thinks that " << butcher.getIdeas(2) << std::endl;
		std::cout << std::endl;
	}
    return 0;
}
