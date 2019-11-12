#include "Part.hpp"

Part::Part(){}

Part::~Part(){}

std::vector<Part *> &Part::getPn()
{
	return pnearby;
}
