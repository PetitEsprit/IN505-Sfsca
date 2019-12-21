#include "Motor.hpp"

Motor::Motor(){}
Motor::~Motor(){}
void Motor::transmit(bool *b)
{
	b[id] = true;
	std::cout << "Part: " << id << std::endl;
}
void Motor::toString()
{
	std::cout << "Motor" << std::endl;
}
