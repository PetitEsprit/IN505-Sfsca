#include <iomanip>
#include <sstream>
#include "Grade.hpp"

Grade::Grade(float grade) :
g(grade),
t(time(NULL))
{}

Grade::Grade(float grade, time_t timestamp) :
g(grade),
t(timestamp)
{}

Grade::~Grade() {}

string Grade::getDate(const char *format)
{
	stringstream s;
	s << put_time(localtime(&t), format);
	return (s.str());
}

float Grade::getGrade()
{
	return (g);
}

time_t Grade::getTimestamp()
{
	return (t);
}
