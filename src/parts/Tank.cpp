#include "Tank.hpp"

Tank::Tank() {}
Tank::~Tank(){}
int Tank::getP1() {return p1;}
int Tank::getP2() {return p2;}
int Tank::getFuel() {return fuel;}
void Tank::setP1(e_state e) {p1 = e;}
void Tank::setP2(e_state e) {p2 = e;}
void Tank::setFuel(e_state e) {fuel = e;}
void Tank::transmit(bool *b)
{
	b[id] = true;
	std::cout << "Part: " << id << std::endl;
}
