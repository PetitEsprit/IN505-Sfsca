#ifndef VALVE_HPP
# define VALVE_HPP
# include "Part.hpp"


class Valve : public Part
{
	bool		closed;
	public:
		Valve(const char *name);
		Valve(const char *name, bool closed);
		~Valve();

		bool isClosed();
        void close();
        void open();
		void supplyFuel();
};

#endif
