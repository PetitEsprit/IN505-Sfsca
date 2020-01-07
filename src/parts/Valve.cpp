#include "Valve.hpp"
#include <iostream>

Valve::Valve(const char *name) : Part(name), closed(false)
{}

Valve::Valve(const char *name, bool closed) : Part(name), closed(closed)
{}

Valve::~Valve()
{}

bool Valve::isClosed()
{
	return (closed);
}

void Valve::close()
{
    closed = true;
}

void Valve::open()
{
    closed = false;
}

void Valve::supplyFuel()
{
	//std::cout << "YEAH from: " << name << std::endl;
	if(closed)
	{
		for(unsigned int i = 0; i < pnearby.size(); i++)
		{
			if(!pnearby[i]->isMarked())
			{
				pnearby[i]->mark();
				pnearby[i]->supplyFuel();
			}
		}
	}
}
