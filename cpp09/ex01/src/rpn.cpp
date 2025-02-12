/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/rpn.hpp"

// equation will never come in empty before there are check done beforehand
Rpn::Rpn( std::string& equation )
{
	std::istringstream stream(equation);
	std::string token;

	while (stream >> token)
	{
		if (token == "*" || token == "/" || token == "+" || token == "-")
		{

		}
		else if ()
		{

		}
			return ;
	}

}

Rpn::~Rpn()
{
}

Rpn::Rpn( const Rpn& ref )
{
	static_cast<void>(ref);
}

Rpn& Rpn::operator=( const Rpn& ref )
{
	if (this == &ref)
		return (*this);;
	static_cast<void>(ref);
	return (*this);
}

//public methods
void	Rpn::outputResult()
{
	std::cout <<
}

// setters
void	Rpn::setResult( int64_t result )
{
	this->_result = result;
}
// getters

const int64_t		Rpn::getResult() const
{
	return(this->_result);
}
