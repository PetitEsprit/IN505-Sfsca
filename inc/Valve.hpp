#ifndef VALVE_HPP
#define VALVE_HPP

#include "Part.hpp"

class Valve : public Part
{
	bool state;
	public:
		Valve();
		~Valve();
		bool getState();
		void transmit(bool *b);
		void toString();
};

#endif
