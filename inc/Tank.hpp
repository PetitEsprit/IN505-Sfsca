#ifndef TANK_HPP
# define TANK_HPP

# include "Part.hpp"

enum e_pump
{
	OFF = 0,
	ON,
	BROKEN,
};

class Tank : public Part
{
	private:
		bool		empty;
		bool		currempty;
		e_pump		p1, p2;

	public:
		// Initialize a tank
		Tank(const char *name);

		// Initialize a tank with a specified fuel
		Tank(const char *name, bool empty);

		// Destroy a tank
		~Tank();

		// Get the main pump status
		e_pump getP1();

		// Get the emergency pump status
		e_pump getP2();

		// Change the main pump status
		void setP1(e_pump e);

		// Change the emergency pump status
		void setP2(e_pump e);

		// Returns true if the fuel tank is empty
		bool isEmpty();
		
		bool isCurrEmpty();
		
		// Drain all fuel from the tank
		void drain();

		// Fill the fuel tank
		void fill();

		void fillAfter();

		// Print a tank in the terminal at the given position
		void print(unsigned int x, unsigned int y);
		
		void supplyFuel();
};

#endif
