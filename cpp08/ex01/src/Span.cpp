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

Span::Span( uint32_t limit ): _max(limit), gen(std::random_device{}())
{
	this->_container.reserve(limit); // making our container fixed sized
}

Span::~Span()
{
}

Span::Span( const Span& ref )
{
	this->_container = ref._container;
	this->_max = ref._max;
}

Span &Span::operator=( const Span& ref )
{
	if (this == &ref)
		return (*this);
	this->_container = ref._container;
	this->_max = ref._max;
	return (*this);	
}

void	Span::addNumber(uint32_t num)
{
	if (this->_container.size() >= this->_max) {
		throw std::overflow_error("Container is full; cannot add more numbers");
	}
	this->_container.push_back(num);
}

uint32_t	Span::shortestSpan()
{
	if (this->_container.size() < 2)
	{
		throw noSpan();
		return (1);
	}
	uint32_t minSpan = UINT32_MAX;
	for (uint32_t i = 0; i < this->_container.size() - 1; ++i)
	{
		for (uint32_t j = i + 1; j < this->_container.size(); ++j)
		{
			uint32_t diff = std::abs(this->_container[i] - this->_container[j]);
			if (diff < minSpan)
				minSpan = diff;
		}
	}
	return (minSpan);
}

uint32_t	Span::longestSpan()
{
	if (this->_container.size() < 2)
	{
		throw noSpan();
		return (1);
	}
	uint32_t maxSpan = 0;
	for (uint32_t i = 0; i < this->_container.size() - 1; ++i)
	{
		for (uint32_t j = i + 1; j < this->_container.size(); ++j)
		{
			uint32_t diff = (this->_container[i] > this->_container[j]) ? this->_container[i] - this->_container[j] : this->_container[j] - this->_container[i];
			if (diff > maxSpan)
				maxSpan = diff;
		}
	}
	return (maxSpan);
}


void	Span::addRange( uint32_t range )
{
	if (range == 0)
		return ;
	if (this->_container.size() + range > this->_max)
		throw std::overflow_error("Range is bigger than size of container");
	std::uniform_int_distribution<uint32_t> dist(0, UINT32_MAX);
	for (uint32_t i = 0; i < range; ++i)
	{
		this->addNumber(dist(gen));
	}
}

const char* Span::noSpan::what() const noexcept
{
	return ("Exception: Container must have at least two elements for span calculation.");
}