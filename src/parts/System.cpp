#include "System.hpp"
#include <iostream>

System::System()
{
	parts[0] = new Tank(); parts[1] = new Tank(); parts[2] = new Tank();
	parts[3] = new Motor(); parts[4] = new Motor(); parts[5] = new Motor();
	parts[6] = new Valve(); parts[7] = new Valve(); parts[8] = new Valve(); //V
	parts[9] = new Valve(); parts[10] = new Valve();//VT
	
}

System::~System()
{
	for(Part *p : parts) delete p;
}

void System::run()
{
	bool hasvisit[11];
	parts[0]->transmit(hasvisit);
}

