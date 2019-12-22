#include "System.hpp"
#include <iostream>

System::System()
{
	motor[M1] = new Motor();
	motor[M2] = new Motor();
	motor[M3] = new Motor();

	tank[T1] = new Tank("T1");
	tank[T2] = new Tank("T2");
	tank[T3] = new Tank("T3");

	valve[V12] = new Valve();
	valve[V13] = new Valve();
	valve[V23] = new Valve();
	valve[VT12] = new Valve();
	valve[VT23] = new Valve();
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

	do
	{
		std::cout << "\033[1J\033[2H";
		if (!s.compare("help"))
			std::cout << "\tType \"exit\" or \"quit\" to quit the program";
		tank[T1]->print(4, 4);
		tank[T2]->print(15, 4);
		tank[T3]->print(26, 4);
		std::cout << "\n\n> ";
		std::cin >> s;
	} while (s.compare("exit") && s.compare("quit"));
}

