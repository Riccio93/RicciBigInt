#pragma once

#include <inttypes.h>
#include <deque>

class BigInt
{
public:
	typedef std::deque<uint32_t> data_t;

	//Constructors
	BigInt();
	BigInt(int32_t);
	BigInt(const BigInt&);

private:
	data_t data;
	bool bIsNegative;

	//Utility
	uint32_t RightPart(uint64_t value) const;
	uint32_t LeftPart(uint64_t value) const;

	//Operations
public:
	BigInt Sum(const BigInt&);
};