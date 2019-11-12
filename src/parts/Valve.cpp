#include "Valve.hpp"

Valve::Valve() : state(OPEN) {}
Valve::~Valve() {}
int Valve::getState() {return state;}
