#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "Part.hpp"

class Motor : public Part
{
	public:
		Motor();
		~Motor();
		void transmit(bool *b);
		void toString();
};

#endif
