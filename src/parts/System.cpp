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

void System::print_tank(Part *p, const char *name)
{
	std::cout << "│";
	if (!p->getState())
		std::cout << "\033[32m";
	std::cout << name << "\033[0m│";
}

void System::print_valve(Part *p, const char *name)
{
	std::cout << "┄";
	if (p->getState())
		std::cout << "\033[31m";
	std::cout << name << "\033[0m┄";
}

void System::run()
{
	std::string s;

	do
	{
		std::cout << "\033[1J\033[0;0H";
		if (!s.compare("help"))
			std::cout << "\tType \"exit\" or \"quit\" to quit the program";
		std::cout << "\n\n\t╭──╮      ╭──╮      ╭──╮\n\t";
		print_tank(parts[T1], "T1");
		print_valve(parts[VT12], "VT12");
		print_tank(parts[T2], "T2");
		print_valve(parts[VT23], "VT23");
		print_tank(parts[T3], "T3");
		std::cout << "\n\t╰──╯      ╰──╯      ╰──╯\n";
		std::cout << "\n\n> ";
		std::cin >> s;
	} while (s.compare("exit") && s.compare("quit"));
}

