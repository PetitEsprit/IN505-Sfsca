#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "Tank.hpp"
#include "Motor.hpp"
#include "Valve.hpp"

class System
{
	private:
		Part *parts[11];
	public:
		System();
		void run();
		~System();
};

#endif
