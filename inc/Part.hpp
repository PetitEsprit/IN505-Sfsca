#ifndef PART_HPP
# define PART_HPP
# include <string>

class Part
{
	public:
		Part();
		virtual ~Part();
		int getId();
		virtual std::string toString();
};

#endif
