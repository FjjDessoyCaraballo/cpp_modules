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

Rpn::Rpn()
{
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

int	Rpn::outputResult( std::string equation )
{
	std::stack<int> stacky;
	std::istringstream stream(equation);
	std::string token;

	// each token that gets the output of stream will be one of the arguments from argv
	while (stream >> token)
	{
		if (token == "*" || token == "/" || token == "+" || token == "-")
		{
			// for one operator there will be the equivalent number of operands plus one - e.g. 1 + 1
			// if we get to the operators clause and there is less than two operands it's an error 
			if (stacky.size() < 2)
				throw std::runtime_error("Error: not enough operands");

			// extract two operators at a time to follow the RPN logic
			int operandB = stacky.top();
			stacky.pop();
			int operandA = stacky.top();
			stacky.pop();
			int result = 0;

			switch (token[0])
			{
				case '*':
					result = operandA * operandB;
					break ;
				case '+':
					result = operandA + operandB;
					break ;
				case '-':
					result = operandA - operandB;
					break ;
				case '/':
					if (operandA == 0)
						throw std::runtime_error("Error: division by zero");
					result = operandA / operandB;
					break ;
				default:
					throw (std::runtime_error("Error: what?"));
					break ;
			}
			stacky.push(result);
		}
		// clause for checking if the input is a number (positive and negative respectively)
		else if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]) && token[0] == '-'))
		{
			bool isNumber = true;
			
			// if the number is negative we will iterate to check the string for garbage
			for (size_t i = 1; i < token.size(); i++)
			{
				if (!isdigit(token[i]))
				{
					isNumber = false;
					break ;
				}
			}
			// this clause runs if there is garbage
			if (!isNumber)
				throw std::runtime_error("Error: invalid digit");

			// all good, we push it into the stack
			int number = std::stoi(token);
			stacky.push(number);
		}
	}
	// check if there is anything left but the result in the stack
	if (stacky.size() > 1)
		throw std::runtime_error("Error: overstacked");

	// for clarity we assign the top of the stack (only number left) to the result
	int result = stacky.top();
	return (result);
}
