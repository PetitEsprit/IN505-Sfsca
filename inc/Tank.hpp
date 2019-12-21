#ifndef TANK_HPP
#define TANK_HPP

#include "Part.hpp"

enum e_state
{
	BROKEN = -1,//pump
	OFF = 0,
	ON = 1,
};

class Tank : public Part
{
	e_state p1, p2, fuel;
	public:
		Tank();
		~Tank();
		e_state getP1();
		e_state getP2();
		e_state getFuel();
		void setP1(e_state e);
		void setP2(e_state e);
		void setFuel(e_state e);
		std::string toString();
};

#endif
