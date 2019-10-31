#ifndef VALVE_HPP
#define VALVE_HPP

#include "e_state.hpp" 

class Valve
{
	e_state state;
	public:
		Valve();
		~Valve();
		int getState();
};

#endif
