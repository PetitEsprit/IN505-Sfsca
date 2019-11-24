#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "e_state.hpp"
#include "Part.hpp"

class Motor : public Part
{
	public:
		Motor();
		~Motor();
		void transmit(bool *b);
};

#endif
