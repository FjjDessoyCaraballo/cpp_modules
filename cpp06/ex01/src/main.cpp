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

int main(void)
{
	Data data = {42};
	Data *dataPtr = &data;

	uintptr_t testPtr;
	testPtr = Serializer::serialize(dataPtr);
	std::cout << "Serialized: " << testPtr << std::endl;

	Data *retPtr;
	retPtr = Serializer::deserialize(testPtr);
	std::cout << "Deserialized: " << retPtr->intValue << std::endl;
	return (0);
}