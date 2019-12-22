#include <iostream>
#include <string>
#include "Tank.hpp"

Tank::Tank(const char *name) : empty(false), p1(ON), p2(OFF), name(name)
{}

Tank::~Tank()
{}

// Get the main pump status
e_pump Tank::getP1()
{
	return (p1);
}

// Get the emergency pump status
e_pump Tank::getP2()
{
	return (p2);
}

// Change the main pump status
void Tank::setP1(e_pump status)
{
	p1 = status;
}

// Change the emergency pump status
void Tank::setP2(e_pump status)
{
	p2 = status;
}

// Returns true if the fuel tank is empty
bool Tank::isEmpty()
{
	return (empty);
}

// Drain all fuel from the tank
void Tank::drain()
{
	empty = true;
}

// Fill the fuel tank
void Tank::fill()
{
	empty = false;
}

// Print a tank in the terminal at the given position
void Tank::print(unsigned int x, unsigned int y)
{
	std::string sx;
	
	sx = (x) ? "\033[" + std::to_string(x) + "C" : "";
	std::cout << "\r\033[" + std::to_string(y) + ";" + std::to_string(x + 1) + "H";
	std::cout << "╭──────╮\n" << sx << "│  ";
	std::cout << (empty ? "\033[31m" : "\033[32m");
	std::cout << name << "\033[0m  │\n";
	std::cout << sx << "│      │\n" << sx << "│";
	std::cout << (p1 == OFF ? "\033[31m" : (p1 == ON ? "\033[32m" : "\033[93m"));
	std::cout << "P1" << "\033[0m  ";
	std::cout << (p2 == OFF ? "\033[31m" : (p2 == ON ? "\033[32m" : "\033[93m"));
	std::cout << "P2\033[0m│\n" << sx << "╰──────╯";
}
