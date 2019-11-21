#ifndef E_STATE_HPP
#define E_STATE_HPP

enum e_state
{
	BROKEN = -1,//pump
	OFF = 0,
	ON = 1,
	CLOSE = OFF,//valve
	OPEN = ON,
	EMPTY = OFF,//Tank
	FULL = ON
};

#endif
