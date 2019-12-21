#include "Valve.hpp"

Valve::Valve() : state(true) {}
Valve::~Valve() {}
bool Valve::getState() {return state;}
void Valve::transmit(bool *b)
{
	b[id] = true;
	std::cout << "Part: " << id << std::endl;
}
void Valve::toString()
{
	std::cout << "Valve" << std::endl;
}
