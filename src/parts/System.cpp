#include "System.hpp"
#include <iostream>

System::System()
{
	parts[T1] = new Tank();
	parts[T2] = new Tank();
	parts[T3] = new Tank();

	parts[M1] = new Motor();
	parts[M2] = new Motor();
	parts[M3] = new Motor();

	parts[V12] = new Valve();
	parts[V13] = new Valve();
	parts[V23] = new Valve();

	parts[VT12] = new Valve();
	parts[VT23] = new Valve();
}

System::~System()
{
	for (Part *p : parts) delete p;
}

void System::run()
{
	std::string s;

	do
	{
		std::cout << "ptdr t ki" << std::endl;
		std::cin >> s;
	} while (s.compare("exit") && s.compare("quit"));
}

