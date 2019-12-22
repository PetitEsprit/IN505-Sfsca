#include "Valve.hpp"

Valve::Valve() : closed(false)
{}

Valve::~Valve()
{}

bool Valve::isClosed()
{
	return (closed);
}
