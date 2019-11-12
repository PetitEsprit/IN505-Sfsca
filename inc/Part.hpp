#ifndef PART_HPP
#define PART_HPP

#include <vector>

class Part
{
	std::vector<Part *> pnearby; // voisins transmetteur
	public:
		Part();
		~Part();
		std::vector<Part *> &getPn(); //Mettre une surchage [] ?
};

#endif
