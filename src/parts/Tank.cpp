#include "Tank.hpp"

Tank::Tank(e_state _p1, e_state _p2, e_state _fuel) : p1(_p1), p2(_p2), fuel(_fuel) {}
Tank::~Tank(){}
int Tank::getP1() {return p1;}
int Tank::getP2() {return p2;}
int Tank::getFuel() {return fuel;}
void Tank::setP1(e_state e) {p1 = e;}
void Tank::setP2(e_state e) {p2 = e;}
void Tank::setFuel(e_state e) {fuel = e;}
