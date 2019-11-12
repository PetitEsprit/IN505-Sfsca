#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "e_state.hpp"
#include "Part.hpp"

class Motor : public Part
{
	e_state state;
	public:
		Motor(e_state inite);
		int getState();
		~Motor();
};

#endif
