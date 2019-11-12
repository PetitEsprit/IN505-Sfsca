#ifndef TANK_HPP
#define TANK_HPP

#include "e_state.hpp"
#include "Part.hpp"

class Tank : public Part
{
	e_state p1, p2;
	public:
		Tank(e_state _p1, e_state _p2);
		~Tank();
		int getP1();
		int getP2();
		void setP1(e_state e);
		void setP2(e_state e);
};

#endif
