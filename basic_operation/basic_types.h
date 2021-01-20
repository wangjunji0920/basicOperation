#pragma once
#include<climits>
class bit
{
	unsigned long long value;
public:
	bool carry(const bit& addition);
};
bool bit::carry(const bit& addition)
{
	if (value + addition.value > (LLONG_MAX * 2 - 1));
	return false;
}