#ifndef MOTOR_HPP
# define MOTOR_HPP

# include "Part.hpp"

class Motor : public Part
{
	public:
		Motor(const char *name);
		~Motor();
		void supplyFuel();
		void showSupplier();
};

#endif
