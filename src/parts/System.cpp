#include "System.hpp"
#include <iostream>

System::System()
{
	motor[M1] = new Motor("M1");
	motor[M2] = new Motor("M2");
	motor[M3] = new Motor("M3");

	tank[T1] = new Tank("T1", true);
	tank[T2] = new Tank("T2", false);
	tank[T3] = new Tank("T3", false);

	valve[V12] = new Valve("V12");
	valve[V13] = new Valve("V13");
	valve[V23] = new Valve("V23");

	valve[VT12] = new Valve("VT12", true);
	valve[VT23] = new Valve("VT23", true);
	
	tank[T1]->addLink(motor[M1]);
	tank[T1]->addLink(valve[V12]);
	tank[T1]->addLink(valve[V13]);
	
	tank[T2]->addLink(motor[M2]);
	tank[T2]->addLink(valve[V12]);
	tank[T2]->addLink(valve[V23]);
	
	tank[T3]->addLink(motor[M3]);
	tank[T3]->addLink(valve[V13]);
	tank[T3]->addLink(valve[V23]);
	
	valve[V12]->addLink(motor[M1]);
	valve[V12]->addLink(motor[M2]);
	valve[V12]->addLink(valve[V13]);
	valve[V12]->addLink(valve[V23]);
	
	valve[V13]->addLink(motor[M1]);
	valve[V13]->addLink(motor[M3]);
	valve[V13]->addLink(valve[V12]);
	valve[V13]->addLink(valve[V23]);
	
	valve[V23]->addLink(motor[M2]);
	valve[V23]->addLink(motor[M3]);
	valve[V23]->addLink(valve[V12]);
	valve[V23]->addLink(valve[V13]);
}

System::~System()
{
	for (Motor *m : motor) delete m;
	for (Tank *t : tank) delete t;
	for (Valve *v : valve) delete v;
}

void System::run()
{
	std::string s;
	
	balanceFuel();
	
	do
	{
		std::cout << "\033[1J\033[2H";
		if (!s.compare("help"))
			std::cout << "\tType \"exit\" or \"quit\" to quit the program";
		tank[T1]->print(4, 4);
		tank[T2]->print(15, 4);
		tank[T3]->print(26, 4);
		std::cout << "\n";
		std::cout << "\n\n> ";
		std::cin >> s;
	} while (s.compare("exit") && s.compare("quit"));
	
	std::cout << "\033[1J\033[2H";
	
	tank[T1]->supplyFuel();
	if(motor[M1]->isMarked()) motor[M1]->addLink(tank[T1]);
	if(motor[M2]->isMarked()) motor[M2]->addLink(tank[T1]);
	if(motor[M3]->isMarked()) motor[M3]->addLink(tank[T1]);
	unmarkAll();
	tank[T2]->supplyFuel();
	if(motor[M1]->isMarked()) motor[M1]->addLink(tank[T2]);
	if(motor[M2]->isMarked()) motor[M2]->addLink(tank[T2]);
	if(motor[M3]->isMarked()) motor[M3]->addLink(tank[T2]);
	unmarkAll();
	tank[T3]->supplyFuel();
	if(motor[M1]->isMarked()) motor[M1]->addLink(tank[T3]);
	if(motor[M2]->isMarked()) motor[M2]->addLink(tank[T3]);
	if(motor[M3]->isMarked()) motor[M3]->addLink(tank[T3]);
	unmarkAll();
	motor[M1]->showSupplier();
	motor[M2]->showSupplier();
	motor[M3]->showSupplier();
}

void System::balanceFuel()
{
	bool emptyT1, emptyT2, emptyT3;
	bool closedVT12, closedVT23;

	emptyT1 = tank[T1]->isEmpty();
	emptyT2 = tank[T2]->isEmpty();
	emptyT3 = tank[T3]->isEmpty();

	closedVT12 = valve[VT12]->isClosed();
	closedVT23 = valve[VT23]->isClosed();

	if(emptyT1 && !emptyT3 && closedVT12 && closedVT23) tank[T1]->fillAfter();

	if(emptyT2)
	{
		if( (!emptyT1 && closedVT12) || (!emptyT3 && closedVT23) ) tank[T2]->fillAfter();
	}
	
	if(emptyT3 && !emptyT1 && closedVT12 && closedVT23) tank[T3]->fillAfter();
}

void System::unmarkAll()
{
	for (Motor *m : motor) m->unmark();
	for (Tank *t : tank) t->unmark();
	for (Valve *v : valve) v->unmark();
}
