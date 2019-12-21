#ifndef SYSTEM_HPP
# define SYSTEM_HPP
# include "Motor.hpp"
# include "Tank.hpp"
# include "Valve.hpp"

enum e_part
{
	T1 = 0,
	T2,
	T3,
	M1,
	M2,
	M3,
	V12,
	V13,
	V23,
	VT12,
	VT23
};

class System
{
	private:
		Part *parts[11];
	public:
		System();
		~System();
		void run();
};

#endif
