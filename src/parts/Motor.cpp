#include "Motor.hpp"
#include <iostream>

Motor::Motor(const char *name) : Part(name) {}

Motor::~Motor() {}

void Motor::supplyFuel()
{
	//std::cout << "YEAH from: " << name << std::endl;
}

void Motor::showSupplier()
{
	std::cout << name << ": "<< std::endl;
	for(unsigned int i = 0; i < pnearby.size(); i++)
		std::cout << " - " << pnearby[i]->name << std::endl;
}
