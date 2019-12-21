#include "Tank.hpp"

Tank::Tank() {}

Tank::~Tank() {}

e_state Tank::getP1() { return p1; }

e_state Tank::getP2() { return p2; }

e_state Tank::getFuel() { return fuel; }

bool Tank::isWorking()
{
	return ((p1 > 0 || p2 > 0) &&  fuel > 0);
}

void Tank::setP1(e_state e) { p1 = e; }

void Tank::setP2(e_state e) { p2 = e; }

void Tank::setFuel(e_state e) { fuel = e; }

std::string Tank::toString()
{
	return "Tank";
}
