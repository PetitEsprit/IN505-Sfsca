#ifndef GRADE_HPP
# define GRADE_HPP
# include <ctime>
# include <string>

using namespace std;

class Grade
{
	private:
		float	g;
		time_t	t;

	public:
		Grade(float grade);
		Grade(float grade, time_t timestamp);
		~Grade();

		/*
		* Get grade date using put_time format
		* ex: "%F %T" stands for "YYYY-MM-DD HH:MM:SS"
		*/
		string	getDate(const char *format);

		// get grade value
		float	getGrade();

		// get timestamp value
		time_t	getTimestamp();
};

#endif
