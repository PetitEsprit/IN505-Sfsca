#ifndef TANK_HPP
#define TANK_HPP

#include "e_state.hpp"

class Tank
{
	e_state p1, p2;
	public:
		Tank();
		~Tank();
		int getP1();
		int getP2();
};

#endif
