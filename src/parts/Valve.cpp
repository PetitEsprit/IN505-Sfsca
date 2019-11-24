#include "Valve.hpp"

Valve::Valve() : state(OPEN) {}
Valve::~Valve() {}
int Valve::getState() {return state;}
void Valve::transmit(bool *b)
{
	b[id] = true;
	std::cout << "Part: " << id << std::endl;
}

