#include "Part.hpp"

int Part::_nbParts = 0;

Part::Part() : id(_nbParts){_nbParts++;}

Part::~Part(){_nbParts--;}

int Part::getId(){return id;}

std::vector<Part *> &Part::getPn()
{
	return pnearby;
}

void Part::addLink(Part* p)
{
	pnearby.push_back(p);
}
