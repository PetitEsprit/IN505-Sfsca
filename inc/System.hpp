#ifndef SYSTEM_HPP
# define SYSTEM_HPP
# include "Motor.hpp"
# include "Tank.hpp"
# include "Valve.hpp"

enum e_motor
{
	M1 = 0,
	M2,
	M3
};

enum e_tank
{
	T1 = 0,
	T2,
	T3
};

enum e_valve
{
	V12 = 0,
	V13,
	V23,
	VT12,
	VT23
};

class System
{
	private:
		Motor *motor[3];
		Tank *tank[3];
		Valve *valve[5];
	public:
		System();
		~System();
		void run();
		void unmarkAll();
		void balanceFuel();
		void supplyFuel();
};

#endif
