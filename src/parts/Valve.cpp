#include "Valve.hpp"

Valve::Valve() : state(true) {}

Valve::~Valve() {}

bool Valve::getState() { return state; }

std::string Valve::toString()
{
	return "Valve";
}
