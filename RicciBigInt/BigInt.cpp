#include "BigInt.h"

//Constructors

BigInt::BigInt() : data(1), bIsNegative(false) 
{
	data[0] = 0;
}

BigInt::BigInt(int32_t intVal) : data(1), bIsNegative(false)
{
	if(intVal < 0)
	{
		bIsNegative = true;
		intVal = -intVal;
	}
	data[0] = intVal;
}

BigInt::BigInt(const BigInt& other) : data(other.data), bIsNegative(other.bIsNegative){ }

//Utility
uint32_t BigInt::RightPart(uint64_t value) const
{
	return value;
}

uint32_t BigInt::LeftPart(uint64_t value) const
{
	return value >> sizeof(uint32_t) * CHAR_BIT;
}

//Operations

//sums the values in the same position in the two deques.
//It also stores the carry of the sum so that it can be part of the next iteration of the sum.
BigInt BigInt::Sum(const BigInt& other)
{
	BigInt result;
	const size_t maxLen = std::max<size_t>(data.size(), other.data.size());
	//Resize auto-initializes the new values at 0
	data.resize(maxLen);
	uint64_t rest = 0;

	//The for loop keeps going until there are values in the deque
	for(size_t i=0; i<maxLen; i++)
	{
		const uint64_t operator1 = data[i];
		//If the other number has no more values, it just sums 0
		const uint64_t operator2 = i < other.data.size() ? other.data[i] : (uint64_t)0;
		const uint64_t partialSum = operator1 + operator2 + rest;
		result.data[i] = RightPart(partialSum);
		rest = LeftPart(partialSum);
	}

	if (rest > 0)
		result.data.push_back(rest);

	return result;
}
