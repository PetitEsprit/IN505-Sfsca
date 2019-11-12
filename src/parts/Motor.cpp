#include "Motor.hpp"

Motor::Motor(e_state inite) : state(inite){}
Motor::~Motor(){}
int Motor::getState() {return state;}
