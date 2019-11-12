#ifndef VALVE_HPP
#define VALVE_HPP

#include "e_state.hpp" 
#include "Part.hpp"

class Valve : public Part
{
	e_state state;
	public:
		Valve();
		~Valve();
		int getState();
};

#endif
