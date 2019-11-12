#include "Tank.hpp"

Tank::Tank(e_state _p1, e_state _p2) : p1(_p1), p2(_p2) {}
Tank::~Tank(){}
int Tank::getP1() {return p1;}
int Tank::getP2() {return p2;}
void Tank::setP1(e_state e) {p1 = e;}
void Tank::setP2(e_state e) {p2 = e;}
