#ifndef TANK_HPP
#define TANK_HPP

#include "e_state.hpp"
#include "Part.hpp"

class Tank : public Part
{
	e_state p1, p2, fuel;
	public:
		Tank(e_state _p1, e_state _p2, e_state _fuel);
		~Tank();
		int getP1();
		int getP2();
		int getFuel();
		void setP1(e_state e);
		void setP2(e_state e);
		void setFuel(e_state e);
};

#endif
