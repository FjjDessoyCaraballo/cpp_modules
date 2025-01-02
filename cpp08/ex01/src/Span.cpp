/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/Span.hpp"

Span::Span( uint32_t limit ): _max(limit)
{
}

Span::~Span()
{
}

Span::Span( const Span& ref )
{
	this->_storage = ref._storage;
	this->_max = ref._max;
}

Span &Span::operator=( const Span& ref )
{
	if (this == &ref)
		return (*this);
	this->_storage = ref._storage;
	this->_max = ref._max;
	return (*this);	
}

void	Span::addNumber(uint32_t num)
{

}

uint32_t	Span::shortestSpan()
{

}

uint32_t	Span::longestSpan()
{
	
}