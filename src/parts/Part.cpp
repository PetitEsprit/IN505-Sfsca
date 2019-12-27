#include "Part.hpp"

Part::Part(const char *name) : name(name)
{}

Part::~Part()
{}

void Part::addLink(Part *p) { pnearby.push_back(p);  }

std::vector<Part *>& Part::getPn() { return pnearby; }

void Part::mark() { marked = true;  }

void Part::unmark() { marked = false; }

bool Part::isMarked() { return marked; }
