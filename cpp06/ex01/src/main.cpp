/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/Serializer.hpp"
#include <stdexcept>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: <object to be serialized>" << std::endl;
		return (EXIT_FAILURE);
	}
	try {
		int x = std::stoi(argv[1]);
		Data data = {x};
		Data *dataPtr = &data;
		// Serializer series(42); proof that Serializer cannot be instantiated


		uintptr_t testPtr;
		testPtr = Serializer::serialize(dataPtr);
		std::cout << "Serialized: " << testPtr << std::endl;

		Data *retPtr;
		retPtr = Serializer::deserialize(testPtr);
		std::cout << "Deserialized: " << retPtr->intValue << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (0);
}