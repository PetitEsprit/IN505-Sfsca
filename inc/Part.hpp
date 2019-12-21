#ifndef PART_HPP
#define PART_HPP

#include <vector>
#include <iostream>

class Part
{
	protected:
		static int _nbParts;
		const int id;
		std::vector<Part *> pnearby; // voisins transmetteur
	public:
		Part(); //State: ON ON FULL
		virtual ~Part();
		int getId();
		std::vector<Part *> &getPn(); //Mettre une surchage [] ?
		void addLink(Part* p);
		virtual void transmit(bool* hasvisit) = 0;
		virtual void toString();
};

#endif
