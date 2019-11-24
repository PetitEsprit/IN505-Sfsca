#include "System.hpp"

System::System()
{
	parts[0] = new Tank(ON,ON,FULL); parts[1] = new Tank(ON,ON,FULL); parts[2] = new Tank(ON,ON,FULL);
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
	
} 

void System::search()
{
	bool hasvisit[11] = {0};
	DFS(parts[0], hasvisit);
	//DFS(parts[1], hasvisit);
	//DFS(parts[2], hasvisit);
}

void System::DFS(Part* p, bool *hasvisit)
{
	
}
